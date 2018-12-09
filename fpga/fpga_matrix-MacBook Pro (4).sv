// fpga_matrix.sv
// Driver for a 32x32 Adafruit LED Matrix 
// Maddie Zug & Simon Posada Fishman

module fpga_matrix(input logic clk, we,
           input logic [9:0] adr_in,
           input logic [2:0] rgb_in,
           output logic [2:0] rgb_a, rgb_b,
           output logic [3:0] row_address,
           output logic outclk, latch, eo );

  logic [9:0] adr_a, adr_b;

  ram mem(clk, we, adr_in, adr_a, adr_b, in, rgb_a, rgb_b);

  typedef enum logic [2:0] {SHIFT_0, SHIFT_1, BLANK, LATCH, DISPLAY} statetype;

  statetype state, nextstate;

  logic [4:0] shift_count;
  logic [3:0] next_row_address;
  logic [16:0] nextdelay, delay;

  always_ff @(posedge clk) begin
    if (delay > 0)
      delay <= delay - 1;
    else begin
      state <= nextstate;
      delay <= nextdelay;

      case (state)
        SHIFT_1: shift_count <= shift_count + 1;
        LATCH: row_address <= row_address + 1;
      endcase
    end
  end

  // State transition logic
  always_comb
    case (state)
      SHIFT_1: nextstate <= SHIFT_0;
      SHIFT_0: if (shift_count == 0) nextstate <= BLANK;
					     else nextstate <= SHIFT_1;
      BLANK:   nextstate <= LATCH;
      LATCH:   nextstate <= DISPLAY;
      DISPLAY: nextstate <= SHIFT_1;

      default: nextstate <= state;
    endcase

   // State transition logic
  always_comb
    case (state)
      SHIFT_1: nextdelay <= 0;
      SHIFT_0: nextdelay <= 0;
      BLANK:   nextdelay <= 200;
      LATCH:   nextdelay <= 100;
      DISPLAY: nextdelay <= 0;

      default: nextdelay <= 0;
    endcase

  // Output logic
  assign outclk = (state == SHIFT_1);
  assign eo = (state == BLANK) || (state == LATCH);
  assign latch = (state == LATCH);
  assign next_row_address = row_address + 1;
  assign adr_a = (next_row_address * 32) + shift_count;
  assign adr_b = adr_a + 512; 

endmodule

module ram #(parameter N = 10, M = 3) 
            (input logic clk, 
            input logic we, 
            input logic [N-1:0] adr_in,
            input logic [N-1:0] adr_a, 
            input logic [N-1:0] adr_b, 
            input logic [M-1:0] din, 
            output logic [M-1:0] dout_a,
            output logic [M-1:0] dout_b); 
  
  logic [M-1:0] mem [2**N-1:0]; 

  initial
      $readmemh("memfile.dat",mem);

  always_ff @(posedge clk) begin
    if (we) mem [adr_in] <= din; 
  
    dout_a <= mem[adr_a]; 
    dout_b <= mem[adr_b]; 
  end

endmodule
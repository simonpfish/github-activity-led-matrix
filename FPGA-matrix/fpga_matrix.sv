// fpga_matrix.sv
// Driver for a 32x32 Adafruit LED Matrix 
// Maddie Zug & Simon Posada Fishman

module fpga_matrix(input logic clk, we, R_in, G_in, B_in,
           input logic [9:0] adr_in,
           output logic [2:0] rgb_a, rgb_b,
           output logic [3:0] row_address,
           output logic outclk, latch, eo );

  logic [2:0] row_a [31:0];
  logic [2:0] row_b [31:0];
  logic read_ab_toggle;

  logic [9:0] adr_out, base_adr_out;
  logic [2:0] d_out;
  logic [2:0] d_in;

  ram mem(clk, we, adr_in[8:0], adr_out, d_in, d_out);

  typedef enum logic [3:0] {READ_A, READ_B, NEXT_ADR, 
                            SHIFT_0, SHIFT_1, 
                            BLANK, LATCH, DISPLAY} statetype;

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

      if (state == SHIFT_1 || state == NEXT_ADR) shift_count <= shift_count + 1;
      if (state == LATCH) row_address <= row_address + 1;
      
      if (state == READ_A) begin
        read_ab_toggle <= 1;
        row_b[shift_count] <= d_out;
      end
      
      if (state == READ_B) begin
        read_ab_toggle <= 0;
        row_a[shift_count] <= d_out;
      end
    end
  end

  // State transition logic
  always_comb
    case (state)
      READ_A: nextstate <= READ_B;
      READ_B: nextstate <= NEXT_ADR;
      NEXT_ADR: if (shift_count == 0) nextstate <= SHIFT_1;
					      else nextstate <= READ_B;
      
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
  assign base_adr_out = (next_row_address * 32) + shift_count;

  always_comb
    if(read_ab_toggle)
      adr_out <= base_adr_out;
    else
      adr_out <= base_adr_out + 512;

  assign rgb_a = row_a[shift_count];
  assign rgb_b = row_b[shift_count];

endmodule

module ram #(parameter N = 10, M = 3) 
            (input logic clk, 
            input logic we, 
            input logic [N-1:0] adr_in,
            input logic [N-1:0] adr_out, 
            input logic [M-1:0] d_in, 
            output logic [M-1:0] d_out); 
  
  logic [M-1:0] mem [2**N-1:0]; 

  initial
      $readmemh("memfile.dat",mem);

  always_ff @(posedge we) 
      mem [adr_in] <= d_in;
  
  assign d_out = mem[adr_out];

endmodule
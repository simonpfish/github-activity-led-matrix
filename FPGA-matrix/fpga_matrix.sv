// fpga_matrix.sv
// Driver for a 32x32 Adafruit LED Matrix 
// Maddie Zug & Simon Posada Fishman

module fpga_matrix(input logic clk, we, R_in, G_in, B_in,
           input logic [9:0] adr_in,
           output logic R0, G0, B0, R1, G1, B1,
           output logic [3:0] row_address,
           output logic outclk, latch, eo );

  logic [9:0] adr0, adr1;
  logic [2:0] out0, out1;

  ram mem(clk, we, adr_in, adr0, adr1, in, out0, out1);

  assign R0 = out0[0];
  assign G0 = out0[1];
  assign B0 = out0[2];

  assign R1 = out1[0];
  assign G1 = out1[1];
  assign B1 = out1[2];

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

      if (state == SHIFT_1) shift_count <= shift_count + 1;
      if (state == LATCH) row_address <= row_address + 1;
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
  assign adr0 = (next_row_address * 32) + shift_count;
  assign adr1 = adr0 + 512; 

endmodule

module ram #(parameter N = 10, M = 3) 
            (input logic clk, 
            input logic we, 
            input logic [N-1:0] adr_in,
            input logic [N-1:0] adr_0, 
            input logic [N-1:0] adr_1, 
            input logic [M-1:0] din, 
            output logic [M-1:0] dout_0,
            output logic [M-1:0] dout_1); 
  
  logic [M-1:0] mem [2**N-1:0]; 

  initial
      $readmemh("memfile.dat",mem);

  always_ff @(posedge clk) 
    if (we) mem [adr_0] <= din; 
  
  assign dout_0 = mem[adr_0]; 
  assign dout_1 = mem[adr_1]; 

endmodule
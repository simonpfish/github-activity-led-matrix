module fpga_matrix(input logic clk,
           output logic R0, G0, B0, R1, G1, B1,
           output logic [3:0] row_address,
           output logic outclk, latch, eo );

  logic [9:0] adr0, adr1;
  logic we, R_wd, G_wd, B_wd;

  assign adr0 = (row_address * 32) + shift_count;
  assign adr1 = adr0 + 512;

  ram R_mem(clk, we, adr0, adr1, R_wd, R0, R1);
  ram G_mem(clk, we, adr0, adr1, G_wd, G0, G1);
  ram B_mem(clk, we, adr0, adr1, B_wd, B0, B1);

  typedef enum logic [2:0] {SHIFT_0, SHIFT_1, BLANK, LATCH, DISPLAY} statetype;
  statetype state, nextstate;

  logic [4:0] shift_count;

  always_ff @(posedge clk) begin
    state <= nextstate;

    if (state == SHIFT_1) shift_count <= shift_count + 1;
    if (state == LATCH) row_address <= row_address + 1;
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

  // Output logic
  assign outclk = (state == SHIFT_1);
  assign eo = (state == BLANK) || (state == LATCH);
  assign latch = (state == LATCH);


endmodule

module ram #(parameter N = 10, M = 1) 
            (input logic clk, 
            input logic we, 
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
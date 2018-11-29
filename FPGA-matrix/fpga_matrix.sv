module fpga_matrix(input logic clk,
           output logic R0, R1, G0, G1, B0, B1,
           output logic [3:0] row_address,
           output logic outclk, latch, eo );
           

  logic [31:0] RArray, GArray, BArray;
  
  assign RArray = 32'hFFF000FF;
  assign GArray = 32'hFFF00000;
  assign BArray = 32'h000FFF00;

  typedef enum logic [2:0] {SHIFT_1, SHIFT_0, BLANK, LATCH, DISPLAY} statetype;
  statetype state, nextstate;

  logic [4:0] shift_count;

  always_ff @(posedge clk) begin
    state <= nextstate;

    R0 <= RArray[shift_count];
    G0 <= GArray[shift_count];
    B0 <= BArray[shift_count];

    R1 <= RArray[shift_count];
    G1 <= GArray[shift_count];
    B1 <= BArray[shift_count];

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
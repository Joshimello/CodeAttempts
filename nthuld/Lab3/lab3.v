module PAT (
  input wire clk,
  input wire reset,
  input wire data,
  output wire flag
);
  reg [3:0] s;
  always @(posedge !clk or posedge reset) begin
    if (reset)
      s <= 7;
    else begin
      case (s)
        7: s = data ? 0 : 7; //xxxx
        0: s = data ? 1 : 4; //xxx1
        1: s = data ? 1 : 2; //xx11
        2: s = data ? 3 : 7; //x110
        3: s = data ? 6 : 4; //1101
        4: s = data ? 5 : 7; //xx10
        5: s = data ? 6 : 4; //x101
        6: s = data ? 1 : 4; //1011
        default: s = 7;
      endcase
    end
  end
  assign flag = (s == 3 || s == 6) ? 1'b1 : 1'b0;
endmodule

module Traffic_Light_Controller(
  input wire CLK, RESET, LR_has_Car,
  output wire [2:0] HW_light, LR_light
);
  reg [3:0] s, c;
  always @(posedge CLK or posedge RESET) begin
    if (RESET) begin
      s = 0; c = 0;
    end else begin
      case (s)
        0: if (c >= 5 && LR_has_Car == 1) begin
          s = 1; c = 0; end
        1: if (c >= 3) begin
          s = 2; c = 0; end
        2: if (c >= 1) begin
          s = 3; c = 0; end
        3: if (c >= 5) begin
          s = 4; c = 0; end
        4: if (c >= 3) begin
          s = 5; c = 0; end
        5: if (c >= 1) begin
          s = 0; c = 0; end
        default: s = 0;
      endcase
    end
    c++;
  end
  assign HW_light = (s == 0) ? 3'b100 : (s == 1) ? 3'b010 : 3'b001;
  assign LR_light = (s == 3) ? 3'b100 : (s == 4) ? 3'b010 : 3'b001;
endmodule
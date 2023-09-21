module happy_verilog_tb;
  parameter delay = 5;

  wire out_G, out_D, out_B;
  reg [3: 0]in;
  integer i;

  wire is;
  assign is = in == 2 || in == 3 || in == 5 || in == 7 || in == 11 || in == 13;

  initial begin
    in = 4'd0;
    for(i = 0; i < 16; i = i + 1)begin
      #delay;
      $display("time = %4d, in = %b, out_G = %b, out_D = %b, out_B = %b", $time, in, out_G, out_D, out_B);
      if((out_G === 1'bx | out_D === 1'bx | out_B === 1'bx | 
          out_G === 1'bz | out_D === 1'bz | out_B === 1'bz) ||
          ( is && (out_G & out_D & out_B) == 0) ||
          (!is && (out_G | out_D | out_B) == 1))
        begin
          $display("You got wrong answer!!");
          $finish;
        end
      in = in + 4'd1;
    end
    $display("Congratulations!!");
    $finish;
  end

  happy_verilog_G hvg(.in(in), .out(out_G));
  happy_verilog_D hvd(.in(in), .out(out_D));
  happy_verilog_B hvb(.in(in), .out(out_B));

endmodule
module HalfAdder(
  input a, b,
  output s, c
);
  xor(s, a, b);
  and(c, a, b);
endmodule


module FullAdder(
  input a, b, cin,
  output sum, cout
);
  wire haS, haC, faC;
  HalfAdder HA0(a, b, haS, haC);
  HalfAdder HA1(haS, cin, sum, faC);
  or(cout, haC, faC);
endmodule


module CLAdder(
  input [3:0]a,
  input [3:0]b,
  input cin,
  output [3:0]sum,
  output cout
);
  wire c1, c2, c3;
  FullAdder FA0(a[0], b[0], cin, sum[0], c1);
  FullAdder FA1(a[1], b[1], c1, sum[1], c2);
  FullAdder FA2(a[2], b[2], c2, sum[2], c3);
  FullAdder FA3(a[3], b[3], c3, sum[3], cout);
endmodule


module TBMultiplier(
  input [1:0]a,
  input [1:0]b,
  output [3:0]p
);
  wire a1, a2, a3;
  and(p[0], a[0], b[0]);
  and(a1, a[0], b[1]);
  and(a2, a[1], b[0]);
  and(a3, a[1], b[1]);
  wire c;
  HalfAdder HA0(a1, a2, p[1], c);
  HalfAdder HA1(a3, c, p[2], p[3]);
endmodule


module Multiplier(
  output [7:0]out,
  input [5:0]in1,
  input [1:0]in2
);
  wire [3:0]p0, p1, p2;
  TBMultiplier MU0(in1[1:0], in2, p0);
  TBMultiplier MU1(in1[3:2], in2, p1);
  TBMultiplier MU2(in1[5:4], in2, p2);
  assign out[1:0] = p0[1:0];
  CLAdder AD0(p1, {p2[1:0], p0[3:2]}, 1'b0, out[5:2], c0);
  HalfAdder HA0(p2[2], c0, out[6], c1);
  HalfAdder HA1(p2[3], c1, out[7], c2);
endmodule
module lab3_tb1;
    reg clk, reset, data;
    wire flag;
    parameter delay = 5;
    integer i;
    PAT lab3(clk, reset, data, flag);
    reg [11:0] data_pattern = 12'b101101011101;
    reg [11:0] reset_pattern = 12'b010000000001;
    initial begin
        $display("cycle | reset | data  | flag");
        clk = 0;
        for(i = 0; i < 12; i = i + 1)begin
            data = data_pattern[i];
            reset = reset_pattern[i];
            #delay clk = ~clk;
            $display("  %2d  |   %b   |   %b   |  %b", $time/10, reset, data, flag);
            #delay clk = ~clk;
        end
        $finish;
    end
endmodule

// module lab3_tb2;
//     reg CLK, RESET, LR_has_Car;
//     wire [2:0] HW_light, LR_light;
//     parameter delay = 5;
//     integer i;
//     Traffic_Light_Controller TLC_Lab3(CLK, RESET, LR_has_Car, HW_light, LR_light);
//     reg [19:0] LR_pattern = 20'b11111100111111100000;
//     initial begin
//         $display("cycle | LR_has_Car |  HW_light  | LR_light");
//         CLK = 0;
//         RESET = 1;
//         LR_has_Car = 0;
//         #delay CLK = ~CLK;
//         #1;
//         $display("  %2d  |     %b      |    %b     |    %b", $time/10, LR_has_Car, HW_light, LR_light);
//         #4 CLK = ~CLK;
//         RESET = 0;
//         for(i = 0; i < 20; i = i + 1)begin
//             LR_has_Car = LR_pattern[i];
//             #delay CLK = ~CLK;
//             #1;
//             $display("  %2d  |     %b      |    %b     |    %b", $time/10, LR_has_Car, HW_light, LR_light);
//             #4 CLK = ~CLK;
//         end
//         $finish;
//     end
// endmodule
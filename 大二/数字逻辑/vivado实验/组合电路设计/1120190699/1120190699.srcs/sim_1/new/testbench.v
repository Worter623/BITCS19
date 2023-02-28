`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/07 17:01:52
// Design Name: 
// Module Name: testbench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench();
    reg[3:0] i;
    wire[2:0] o;
    //仿真开始时，先定义输入为0010，输出应为001
    initial begin
        i=4'b0010;
        //10纳秒以后，定义输入为0101，输出应为010
        #10;
        i=4'b0101;
        //又过了10纳秒，定义输入为1000，输出应为011
        #10;
        i=4'b1000;
        //又过了10纳秒，定义输入为1101，输出应为100
        #10;
        i=4'b1101;
    end
    //寄存器i为输入，wire向量记录输出
    sqrt  test(i,o);
    
endmodule

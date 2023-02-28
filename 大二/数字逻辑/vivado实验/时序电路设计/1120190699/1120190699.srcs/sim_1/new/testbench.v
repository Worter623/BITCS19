`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/07 23:13:33
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
    /*线型变量Z存储被测module反馈的输出
    寄存器变量clk，X，reset为被测module提供输入*/
    wire Z;
    reg clk,X,reset;
    
    /*定义被测序列为一个11 bit位的数组
    存入寄存器内由低位到高位存储
    定义一个integer在for循环语句中使用
    初始化integer为0*/
    reg [0:10] test_sequence=11'b100_0010_0010;
    integer i=0;

    SeqDetect test(clk,reset,X,Z);
    
    /*提供时钟周期信号，每隔50纳秒改变一次*/
    always begin
        clk=1'b1;
        #50;
        clk=1'b0;
        #50;
    end
    
    /*仿真开始时，进程激活reset，
    使状态机初始化，处于状态S
    reset失效后，用for循环语句每隔100纳秒
    加载存储在test_sequence中的X输入值
    输入值加载的时间是在时钟的上升沿
    最后用stop语句结束仿真*/
    initial begin
        reset=1'b1;
        X=1'b0;
        #20;
        reset=1'b0;
        for(i=0;i<11;i=i+1)
        begin
            X=test_sequence[i];
            #100;
        end
        $stop;
    end
   
endmodule

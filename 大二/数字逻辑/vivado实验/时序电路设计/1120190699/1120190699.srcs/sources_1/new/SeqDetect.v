`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/07 22:22:49
// Design Name: 
// Module Name: SeqDetect
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

/*通过定义三个独立的、并行的进程来实现状态图
因此使用事件控制语句*/
module SeqDetect(clk,reset,X,Z);
    /*声明并定义输入输出，默认输入都是wire型变量，
    实际上输入也只能是wire型变量
    而输出因为需要在always语句内部被赋值，
    而在always内部被赋值的只能是reg类型变量，
    所以只能将它定义为reg型变量*/
    input clk,X,reset;
    output reg Z;
    /*用3bit位的寄存器数组来存储当前状态和下一状态*/
    reg [2:0] state,next_state;
    //用参数语句为S、A、B、C、D五个状态赋状态代码，它们都是3bit位的
    parameter S=3'b000,A=3'b001,B=3'b010,C=3'b011,D=3'b100;
    
    /*第一个进程：描述用于存储序列识别器状态的状态寄存器
    因为是时序逻辑，用if-else语句、并行执行的非阻塞赋值语句
    每次clk从0变为1，或者当reset为1，该进程将会被执行
    如果此时reset为1，还未开始检测输入序列，先初始化当前状态为状态S
    如果reset为0，代表仿真已经开始，在时钟的上升触发沿
    将下一状态的值赋给当前状态*/
    always @(posedge clk or posedge reset)
    begin
        if (reset)
            state<=S;
        else
            state<=next_state;
    end
    
    /*第二个进程：描述下一状态函数，定义状态转移条件
    由于该进程是组合逻辑，用顺序执行的阻塞赋值语句，
    无论何时只要输入发生变化或者状态发生变化，进程就会被执行
    因为这里需要用到多路判断，所以用case语句而不是if-else
    这里实现的是基于当前状态和输入X判断下一状态
    其实就是实现了状态机图里面的每一条线*/    
    always @(X or state)
    begin
        case(state)
            S: next_state = X ? S : A;
            A: next_state = X ? S : B;
            B: next_state = X ? S : C;
            C: next_state = X ? S : D;
            D: next_state = X ? S : D;
        endcase
    end
    
    /*第三个进程：描述输出函数，给输出Z赋值
    由于该进程是组合逻辑，用顺序执行的阻塞赋值语句
    执行进程的条件和第二个进程相同
    本电路中，输出行为是TCI
    在状态S、A、B、C中，输出都是默认值0
    在状态D中，如果输入X=0，那么输出1*/  
    always @(X or state)
    begin
        case(state)
            S: Z=1'b0;
            A: Z=1'b0;
            B: Z=1'b0;
            C: Z=1'b0;
            D: Z=X ? 1'b0 : 1'b1;
        endcase
    end
    
endmodule

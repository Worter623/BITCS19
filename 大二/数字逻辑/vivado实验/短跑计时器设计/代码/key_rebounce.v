`timescale 1ns / 1ps               //定义时间单位和仿真精度

module key_rebounce(                //定义输入输出端口
    input       I_clk,              //系统时钟
    input       I_rst_n,            //复位信号
    input       I_key_in,           //按键输入信号
    output reg  O_key_out           //按键去抖输出信号
    );
    
    reg R_key_in0;          //记录上个时钟周期的按键输入信号
    reg [19:0] R_count;     //计数寄存器
    
    wire W_change;          //按键输入改变信号
    
    //parameter   C_COUNTER_NUM = 5;
    parameter   C_COUNTER_NUM = 180000;
    
    always@(posedge I_clk or negedge I_rst_n)
        if(!I_rst_n)//复位处理
            R_key_in0 <= 0;
        else        //记录按键输入
            R_key_in0 <= I_key_in;
    //如果前后两个时钟按键输入数据不同，将此信号置为1        
    assign W_change=(I_key_in & !R_key_in0)|(!I_key_in & R_key_in0);
    
    always@(posedge I_clk or negedge I_rst_n)
        if(!I_rst_n)    //复位处理
            R_count <= 0;
        else if(W_change)//按键输入发生改变，重新开始计数   
            R_count <= 0;
        else 
            R_count <= R_count + 1;
    
    always@(posedge I_clk or negedge I_rst_n)
        if(!I_rst_n)    //复位处理
            O_key_out <= 0;  
        else if(R_count >= C_COUNTER_NUM - 1)//更改输出信号
            O_key_out <= I_key_in;

endmodule


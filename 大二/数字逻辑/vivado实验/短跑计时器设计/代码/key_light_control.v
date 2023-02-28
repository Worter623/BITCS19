`timescale 1ns / 1ps               //定义时间单位和仿真精度

module key_light_control(           //定义输入输出端口
    input       I_clk,              //系统时钟
    input       I_rst_n,            //复位信号
    input       I_key,              //按键输入信号
    output      [6:0] O_led,        //七段数码管LED信号
    output      [1:0] O_dx          //七段数码管段选信号
    );
    
    wire        W_add_able;         //按键去抖后信号
    key_rebounce U_key_rebounce     //调用按键去抖模块
    (
        .I_clk          (I_clk),           
        .I_rst_n        (I_rst_n),          
        .I_key_in       (I_key),   
        .O_key_out      (W_add_able)
    );
    
    reg [7:0]   R_num;              //显示数字寄存器
    reg         R_added;            //确保一次按键响应一次自增操作
    
    always @(posedge I_clk or negedge I_rst_n)
    begin
        if(!I_rst_n)
        begin//复位处理
            R_num <= 0;
            R_added <= 0;
        end
        else if(W_add_able == 1)
        begin//按键信号为高电平
            if(R_added == 0)
            begin//此次按键没有执行自增操作，自增并将信号置为1，暂停自增行为
                R_num <= R_num + 1;
                R_added <= 1;
            end
        end
        else
        begin//按键信号为低电平，将信号置为0，可以继续自增
            R_added <= 0;
        end
    end

    light_show U_light_show     //调用数码管显示模块
    (
        .I_clk              (I_clk),
        .I_rst_n            (I_rst_n),
        .I_show_num         (R_num),
        .O_led              (O_led),
        .O_dx               (O_dx)
    );

endmodule


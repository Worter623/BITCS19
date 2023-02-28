`timescale 1ns / 1ps

module sim();
    reg clk, rst_n, key;    //模块输入信号设置为reg型
    
    wire [6:0] led;         //模块输出信号设置为wire型
    wire [1:0] dx;
    
    parameter period = 20;  //一时钟周期时间
    //调用想要进行仿真的模块
    key_light_control U_key_light_control
    (
        .I_clk              (clk),
        .I_rst_n            (rst_n),
        .I_key              (key),
        .O_led              (led),
        .O_dx               (dx)
    );
    //模拟时钟信号
    always begin
        clk = 1'b0;
        #(period/2); //延时半个period
        clk = 1'b1;
        #(period/2);
    end
    
    always begin
        rst_n = 1'b0;
        key = 1'b0;
        #(period/2);
        
        //按键去抖测试
        rst_n = 1'b1;
        key = 1'b1;
        #(4*period);
        key = 1'b0;
        #period;
        
        //按键控制测试
        key = 1'b1;
        #(50*period);
        key = 1'b0;
        #(50*period);
        key = 1'b1;
        #(50*period);
        key = 1'b0;
        #(1000*period);
    end

endmodule

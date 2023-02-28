`timescale 1ns / 1ps               //定义时间单位和仿真精度

module light_show(                  //定义输入输出端口
    input       I_clk,              //系统时钟
    input       I_rst_n,            //复位信号
    input       [7:0] I_show_num,   //输入8-bit数据
    output      [6:0] O_led,        //七段数码管LED信号
    output      [1:0] O_dx          //七段数码管段选信号
    );
    
    parameter   C_COUNTER_NUM = 1000000;    
    //parameter   C_COUNTER_NUM = 10; //计数器峰值
    
    reg  [3:0]  R_temp;             //当前显示的4-bit数据寄存器                
    reg  [1:0]  R_dx_temp;          //段选信号寄存器
    reg  [32:0] R_counter;          //计数器寄存器
    
    always@(posedge I_clk or negedge I_rst_n)
    begin
        if(!I_rst_n)          
        begin       //复位处理
            R_dx_temp <= 2'b01;
            R_temp <= I_show_num[3:0];
            R_counter <= 0;
        end
        else if(R_dx_temp == 2'b01 && R_counter >= C_COUNTER_NUM)
        begin       //显示高4-bit数据
            R_temp <= I_show_num[7:4];
            R_dx_temp <= 2'b10;
            R_counter <= 0;
        end
        else if(R_dx_temp == 2'b10 && R_counter >= C_COUNTER_NUM)
        begin       //显示低4-bit数据
            R_temp <= I_show_num[3:0];
            R_dx_temp <= 2'b01;
            R_counter <= 0;
        end
        else
        begin       //计数器自增
            R_counter <= R_counter + 1;
        end
    end
    
    //led端信号
    assign O_led[0] = (R_temp == 4'b0000||R_temp == 4'b0001||R_temp == 4'b0111
                            ||R_temp == 4'b1100)?0:1;
    assign O_led[1] = (R_temp == 4'b0001||R_temp == 4'b0010||R_temp == 4'b0011
                            ||R_temp == 4'b0111||R_temp == 4'b1101)?0:1;
    assign O_led[2] = (R_temp == 4'b0001||R_temp == 4'b0011||R_temp == 4'b0100
                            ||R_temp == 4'b0101||R_temp == 4'b0111||R_temp == 4'b1001)?0:1;
    assign O_led[3] = (R_temp == 4'b0001||R_temp == 4'b0100||R_temp == 4'b0111
                            ||R_temp == 4'b1010||R_temp == 4'b1111)?0:1;
    assign O_led[4] = (R_temp == 4'b0010||R_temp == 4'b1100||R_temp == 4'b1110
                            ||R_temp == 4'b1111)?0:1;
    assign O_led[5] = (R_temp == 4'b0101||R_temp == 4'b0110||R_temp == 4'b1011
                            ||R_temp == 4'b1100||R_temp == 4'b1110||R_temp == 4'b1111)?0:1;
    assign O_led[6] = (R_temp == 4'b0001||R_temp == 4'b0100||R_temp == 4'b1011
                            ||R_temp == 4'b1101)?0:1;
    //段选信号
    assign O_dx = R_dx_temp;   
endmodule

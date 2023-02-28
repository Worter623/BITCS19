`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/07 16:08:06
// Design Name: 
// Module Name: sqrt
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

//仅使用nand与非门  not反相器对电路图进行结构化描述实现
//nand (output,input,...)
//not (output,...,input)
module sqrt(input wire[3:0] i,output wire[2:0] o);
    /*先定义好输入是一个一个4bit位宽的向量i，输出是一个3bit位宽的向量o*/
    
    //由于wire类型是verilog语言默认的数据类型，因此为方便起见以下的节点将省略wire声明
    not (inva,i[0]),(invb,i[1]),(invc,i[2]),(invd,i[3]);
    //先描述o[0]的输出
    nand 
        y(y_out,inva,invb),
        u1(u1_out,i[0],i[1]);
    not
        invu1(invu1_out,u1_out),
        invy(invy_out,y_out);
    nand
        u2(u2_out,invu1_out,invd),
        u3(u3_out,invy_out,invd),
        u4(u4_out,u3_out,invc);
    nand (o[0],u4_out,u2_out);
    //描述o[1]的输出   
    nand
        u5(u5_out,i[2],invd),
        u6(u6_out,i[2],y_out),
        u7(u7_out,i[3],u6_out),
        u8(u8_out,u7_out,u5_out);
     not  (invu8,u8_out);
     nand  (o[1],invu8,u2_out);
     //描述o[2]的输出
     nand
        u9(u9_out,i[2],i[3]);
     not  (invu9,u9_out);
     nand
        u10(u10_out,invu9,y_out);
     not  (o[2],u10_out);
endmodule

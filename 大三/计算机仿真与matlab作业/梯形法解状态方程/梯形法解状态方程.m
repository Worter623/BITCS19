clear;clc;
format long;
%赋初值，用y1和y2两个矩阵记录每一次的迭代结果
h = 0.1;
y1 = zeros(1,200);
y2 = zeros(1,200);
y1(1) = 0;
y2(1) = 1;

%使用梯形法迭代，输出迭代结果
for i=1:200
    y2(i+1) = 2/(2+h+h^2)*(y2(i)+h/2*(-4*y1(i)-(1+h)*y2(i)+10));
    y1(i+1) = y1(i)+h/2*(y2(i)+y2(i+1));  
end

%输出结果并画图
y1
y2
x = 0:0.1:20;
plot(x,y1)
hold on;
plot(x,y2)
grid on;
legend ('y1','y2')
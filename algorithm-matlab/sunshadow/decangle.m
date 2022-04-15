function [ decangle_ ] = decangle( n )
%计算太阳赤纬角 n为一个在一年中的序数
%   返回结果为弧度制
b=2*pi*(n-1)/365;
decangle_ = 0.006918-0.399912*cos(b)+0.070257*sin(b)-0.006758*cos(2*b)+0.000907*sin(2*b)-0.002697*cos(3*b)+0.00148*sin(3*b);
end


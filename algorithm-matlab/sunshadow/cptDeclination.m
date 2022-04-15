function [ Declination ] = cptDeclination( d )
%计算太阳赤纬角 d为一天在一年中的序数
%单位弧度
b=2*pi*(d-1)./365;
Declination = 0.006918-0.399912*cos(b)+0.070257*sin(b)...
-0.006758*cos(2*b)+0.000907*sin(2*b)-0.002697*cos(3*b)+0.00148*sin(3*b);
end


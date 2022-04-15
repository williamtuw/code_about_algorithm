function [ tk ] = cptTk( tk0,longitude,d )
% 计算tk当地时角单位为度
%latitude单位为度
B=360*(d-81)/365;
errort=(9.87*sin(2*B)-7.53*cos(B)-1.5*sin(B))/60;
tk=15*(mod(tk0+longitude/15+errort+48,24)-12);
end


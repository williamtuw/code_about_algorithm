function [ result ] = isget2point( fromp,destp,threshold )
%ISGET2POINT 此处显示有关此函数的摘要
%   此处显示详细说明
if sqrt(sum((fromp-destp).^2)) <threshold
    result=1 ;
    
else
    result =0;
end
end


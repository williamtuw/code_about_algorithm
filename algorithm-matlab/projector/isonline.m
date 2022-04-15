function [ result ] = isonline(func,t,p0)
%ISONLINE 此处显示有关此函数的摘要
%   此处显示详细说明
p =projector(func,0,t,0,p0);
distance = sqrt(sum((p-p0).^2));
if distance < 1e-8
    result = 1;
else
    result = 0;
end

end


function [ p ] = refector( funcs,t,p0 )
%REFECTOR 此处显示有关此函数的摘要
%   此处显示详细说明
 p = projector(funcs,t,p0);
p =  2*p-p0;
end


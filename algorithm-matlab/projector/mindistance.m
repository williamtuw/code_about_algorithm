function [ distance ] = mindistance( p0,points )
%MINDISTANCE 此处显示有关此函数的摘要
%   此处显示详细说明
sizep = size(points);
distance = min(sqrt(sum((points-repmat(p0,sizep(1),1)).^2,2)));
end


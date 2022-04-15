function [ dateString ] = dtostr( d )
%DTOSTR 此处显示有关此函数的摘要
%   此处显示详细说明
dateString=datestr(datenum(2015,1,1)+d-1,'mm/dd');
end


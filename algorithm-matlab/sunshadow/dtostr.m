function [ dateString ] = dtostr( d )
%DTOSTR �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
dateString=datestr(datenum(2015,1,1)+d-1,'mm/dd');
end


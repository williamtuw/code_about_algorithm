function [ tk ] = cptTkunpunished( tk0,longitude)
% ����tk����ʱ�ǵ�λΪ��
%latitude��λΪ��
tk=15*(mod(tk0+longitude/15+48,24)-12);
end


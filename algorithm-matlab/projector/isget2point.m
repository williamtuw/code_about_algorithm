function [ result ] = isget2point( fromp,destp,threshold )
%ISGET2POINT �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
if sqrt(sum((fromp-destp).^2)) <threshold
    result=1 ;
    
else
    result =0;
end
end


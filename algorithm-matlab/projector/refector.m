function [ p ] = refector( funcs,t,p0 )
%REFECTOR �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
 p = projector(funcs,t,p0);
p =  2*p-p0;
end


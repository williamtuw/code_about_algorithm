function [ distance ] = mindistance( p0,points )
%MINDISTANCE �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
sizep = size(points);
distance = min(sqrt(sum((points-repmat(p0,sizep(1),1)).^2,2)));
end


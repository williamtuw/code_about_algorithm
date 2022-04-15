function [ result ] = isonline(func,t,p0)
%ISONLINE �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
p =projector(func,0,t,0,p0);
distance = sqrt(sum((p-p0).^2));
if distance < 1e-8
    result = 1;
else
    result = 0;
end

end


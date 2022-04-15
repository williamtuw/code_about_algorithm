function [ p ] = projector( funcs,t,p0 )
%funcs 曲线参数方程
%参数范围t
% x0,y0 定点
len = length(funcs);
points = zeros(len,2);
for i=1:1:len
    while abs(t(i,1)-t(i,2))>1e-8
    p_left = funcs{i}(t(i,1));
    p_right  = funcs{i}(t(i,2));
    
    if sum((p_left-p0).^2) > sum((p_right-p0).^2)
        t(i,1) = sum(t(i,:))/2;
    else
        t(i,2) = sum(t(i,:))/2;
    end
    
    end
    points(i,:) = p_left;
end
    
[~,index] = min(sum((points - repmat(p0,len,1)).^2,2));
p = points(index,:);

end


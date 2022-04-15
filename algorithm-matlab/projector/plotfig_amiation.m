function [ ] = plotfig_amiation( points,constraint_ps,constra_ps_style,legends,start,N ,beta,maxsteps)
%作图函数

%legends  为对应constraint_ps的图例



%8个算法的轨迹样式  顺序为'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}
color ={'r','g','b','y','m','c','k',[0.8,0.6,0.3]};
type = {'<','>','^','v','s','d','+','o'};

n = length(constraint_ps);


figure
hold on
title(['β=',num2str(beta)],'fontsize',14);
 axis equal
 axis off
% 约束线 (S,M,Sbar,C)
for i=1:1:n
    ps = cell2mat(constraint_ps(i));
    H(i) = plot(ps(:,1),ps(:,2),cell2mat(constra_ps_style(i)),'linewidth',4);  
end
%初始点
H(n+1)=plot(start(1),start(2),'ko','markersize',10,...
    'markerfacecolor','w');

%制作动画
for j=1:1:maxsteps-1

    

for i=1:1:8
     
     PH(i) = plot(points(j:j+1,1,i),points(j:j+1,2,i) ,'marker',cell2mat(type(i)),...
              'color',cell2mat(color(i)),...
    'linewidth',4,...
    'markersize',8,...
    'markerfacecolor','w');
   
end
%legend([H(1:1:length(legends)),H(n+1),PH],[legends,{'start','ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'}],'fontsize',12);


mov(j)=getframe();

%转成gif图片,只能用256色
    im = frame2im(mov(j));
    [I,map] = rgb2ind(im,256);
    %写入 GIF89a 格式文件    
    if j== 1;
        imwrite(I,map,'multi.gif','GIF', 'Loopcount',inf,'DelayTime',0.15);
    else
        imwrite(I,map,'multi.gif','GIF','WriteMode','append','DelayTime',0.15);
    end    
    
    

end

movie(mov,20,5);
end



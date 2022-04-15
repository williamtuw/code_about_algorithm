function [ ] = plotfig( points,constraint_ps,constra_ps_style,legends,start,N ,beta,maxsteps)
%作图函数

%legends  为对应constraint_ps的图例



%8个算法的轨迹样式  顺序为'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}
color ={'r','g','b','y','m','c','k',[0.8,0.6,0.3]};
type = {'<','>','^','v','s','d','+','o'};

n = length(constraint_ps);


% 迭代过程图 
figure
hold on
title(['β=',num2str(beta)],'fontsize',14);
 
% 约束线 (S,M,Sbar,C)
for i=1:1:n
    ps = cell2mat(constraint_ps(i));
    H(i) = plot(ps(:,1),ps(:,2),cell2mat(constra_ps_style(i)),'linewidth',4);  
end
%初始点
H(n+1)=plot(start(1),start(2),'ko','markersize',10,...
    'markerfacecolor','w');



% 轨迹图
for i=1:1:8
     
     PH(i) = plot(points(:,1,i),points(:,2,i) ,'marker',cell2mat(type(i)),...
              'color',cell2mat(color(i)),...
    'linewidth',4,...
    'markersize',8,...
    'markerfacecolor','w');
   
end
axis equal
legend([H(1:1:length(legends)),H(n+1),PH],[legends,{'start','ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'}],'fontsize',12);



%计算速度和加速度

acceleration = zeros(maxsteps,8);
velocities= zeros(maxsteps+1,8);
for i=1:1:8
   for j=2:1:maxsteps+1
   velocities(j,i) = sqrt(sum((points(j,:,i)-points(j-1,:,i)).^2));
   acceleration(j,i) = velocities(j,i)-velocities(j-1,i);
   end
end

% 速度图
figure
hold on
title(['β=',num2str(beta)],'fontsize',14);
for i=1:1:8
     plot(velocities(1:25,i) ,'marker',cell2mat(type(i)),...
              'color',cell2mat(color(i)),...
    'linewidth',4,...
    'markersize',8,...
    'markerfacecolor','w');     
end

legend({'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'},'fontsize',12);
xlabel('#iterations','fontsize',14);
ylabel('velocities','fontsize',14);

% 加速度图
figure
hold on
title(['β=',num2str(beta)],'fontsize',14);
for i=1:1:8    
     plot(acceleration(1:25,i) ,'marker',cell2mat(type(i)),...
              'color',cell2mat(color(i)),...
    'linewidth',4,...
    'markersize',8,...
    'markerfacecolor','w');     
end
legend({'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'},'fontsize',12);
xlabel('#iterations','fontsize',14);
ylabel('Force','fontsize',14);



%N值图
figure
bar(N,'w');
set(gca,'xTickLabel',{'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'});
ylabel('#Iteration','fontsize',14);
xlabel('algorithms','fontsize',14);
title('各算法收敛所需步数柱状图','fontsize',14);


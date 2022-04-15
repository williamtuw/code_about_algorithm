clc
clear
p0 = [0.8,0];
pend=[-1,0];
ts = [-50,50];
tm = [0,2*pi-2e-10;0,2*pi-2e-10;0,2*pi-2e-10;0,2*pi-2e-10];
tbar = [-50,50];
maxsteps = 100;
points = zeros(maxsteps+1,2,8);
mulstep = 0;
beta = 0.95;
N=zeros(1,8);
[points(:,:,1),N(1)] = ER({@mline2,@mline,@mline3,@mline4},{@sline},ts,tm,p0,pend,maxsteps,mulstep);
[points(:,:,2),N(2)] = SF({@mline2,@mline,@mline3,@mline4},{@sline},ts,tm,p0,pend,maxsteps,mulstep);
[points(:,:,3),N(3)] = HIO({@mline2,@mline,@mline3,@mline4},{@sline},{@sbarline},ts,tm,tbar,p0,pend,maxsteps,beta,mulstep);
[points(:,:,4),N(4)] = DM({@mline2,@mline,@mline3,@mline4},{@sline},ts,tm,p0,pend,maxsteps,beta,mulstep);
[points(:,:,5),N(5)] = ASR({@mline2,@mline,@mline3,@mline4},{@sline},ts,tm,p0,pend,maxsteps,mulstep);
[points(:,:,6),N(6)] = HPR({@mline2,@mline,@mline3,@mline4},{@sline},ts,tm,p0,pend,maxsteps,beta,mulstep);
[points(:,:,7),N(7)] = RAAR({@mline2,@mline,@mline3,@mline4},{@sline},ts,tm,p0,pend,maxsteps,beta,mulstep);
[points(:,:,8),N(8)] = HIO_ER({@mline2,@mline,@mline3,@mline4},{@sline},{@sbarline},ts,tm,tbar,p0,pend,maxsteps,beta,mulstep);



t1 = -2:0.01:2;
t2 = 0:0.01:2*pi-1e-8;
p1 = sline(t1);
p3 = mline(t2);
p2 = mline2(t2);
psbar = sbarline(t1);
p4=mline3(t2);
p5=mline4(t2);
% figure
% hold on
% title(['β=',num2str(beta)],'fontsize',14);
% H = plot(p1(:,1),p1(:,2),'b',psbar(:,1),psbar(:,2),'--k',p2(:,1),p2(:,2),'k',p3(:,1),p3(:,2),'k',p5(:,1),p5(:,2),'k',p4(:,1),p4(:,2),'k'...
%    ,'linewidth',4);
% H(10)=plot(p0(1),p0(2),'ko','markersize',10,...
%     'markerfacecolor','w');
% 
% 
% 
% for i=1:1:8
%      
%      PH(i,1) = plot(points(:,1,i),points(:,2,i) ,'marker',cell2mat(type(i)),...
%               'color',cell2mat(color(i)),...
%     'linewidth',4,...
%     'markersize',8,...
%     'markerfacecolor','w');
%    
% 
%     
%  
%     
%     
%         
% end
%    axis equal
% legend([H([1,2,3,10]);PH],{'Support','C_S_u_p_p_o_r_t','Modulus','start','ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'},'fontsize',12);
% 
% 
% 
% %计算速度和加速度
% 
% acceleration = zeros(maxsteps,8);
% velocities= zeros(maxsteps+1,8);
% for i=1:1:8
%    for j=2:1:maxsteps+1
%    velocities(j,i) = sqrt(sum((points(j,:,i)-points(j-1,:,i)).^2));
%    acceleration(j,i) = velocities(j,i)-velocities(j-1,i);
%    
%    end
%     
% end
% 
% figure
% hold on
% title(['β=',num2str(beta)],'fontsize',14);
% for i=1:1:8
%      
%      plot(velocities(1:25,i) ,'marker',cell2mat(type(i)),...
%               'color',cell2mat(color(i)),...
%     'linewidth',4,...
%     'markersize',8,...
%     'markerfacecolor','w');     
% end
% 
% legend({'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'},'fontsize',12);
% xlabel('#iterations','fontsize',14);
% ylabel('velocities','fontsize',14);
% 
% 
% figure
% hold on
% title(['β=',num2str(beta)],'fontsize',14);
% for i=1:1:8
%      
%      plot(acceleration(1:25,i) ,'marker',cell2mat(type(i)),...
%               'color',cell2mat(color(i)),...
%     'linewidth',4,...
%     'markersize',8,...
%     'markerfacecolor','w');     
% end
% legend({'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'},'fontsize',12);
% xlabel('#iterations','fontsize',14);
% ylabel('Force','fontsize',14);
% 
% %N值图
% figure
% 
% bar(N,'w');
% set(gca,'xTickLabel',{'ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'});
% ylabel('#Iteration','fontsize',14);
% xlabel('algorithms','fontsize',14);
% title('各算法收敛所需步数柱状图','fontsize',14);
% 



plotfig_amiation(points,{p1,psbar,p4,p2,p3,p5},{'b','--k','k','k','k','k',},{'Support','C_S_u_p_p_o_r_t','Modulus'},p0,N,beta,maxsteps);














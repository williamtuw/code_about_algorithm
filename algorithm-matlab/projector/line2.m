clc
clear
p0 = [3,0];
ts = [-50,50];
tm = [-50,50];
tbar = [-50,50];
maxsteps = 100;
points = zeros(maxsteps+1,2,8);
mulstep = 0;
beta = 0.75;
points(:,:,1) = ER({@mline2},{@sline},ts,tm,p0,maxsteps,mulstep);
points(:,:,2) = SF({@mline2},{@sline},ts,tm,p0,maxsteps,mulstep);
points(:,:,3) = HIO({@mline2},{@sline},{@sbarline},ts,tm,tbar,p0,maxsteps,beta,mulstep);
points(:,:,4) = DM({@mline2},{@sline},ts,tm,p0,maxsteps,beta,mulstep);
points(:,:,5) = ASR({@mline2},{@sline},ts,tm,p0,maxsteps,mulstep);
points(:,:,6) = HPR({@mline2},{@sline},ts,tm,p0,maxsteps,beta,mulstep);
points(:,:,7) = RAAR({@mline2},{@sline},ts,tm,p0,maxsteps,beta,mulstep);
points(:,:,8) = HIO_ER({@mline2},{@sline},{@sbarline},ts,tm,tbar,p0,maxsteps,beta,mulstep);







t1 = -2:0.01:2;
t2 = 0:0.01:2*pi-1e-8;
p1 = sline(t1);
% p3 = mline(t1);
p2 = mline2(t1);
psbar = sbarline(t1);

% p4=cline(t1);

figure
hold on

title(['β=',num2str(beta)],'fontsize',14);
H = plot(p1(:,1),p1(:,2),'b',psbar(:,1),psbar(:,2),'--k',p2(:,1),p2(:,2),'k'...
   ,'linewidth',4);
H(10)=plot(p0(1),p0(2),'ko','markersize',10,...
    'markerfacecolor','w');


color ={'r','g','b','y','m','c','k',[0.8,0.6,0.3]};
type = {'<','>','^','v','s','d','+','o'};

for i=1:1:8
     
     PH(i,1) = plot(points(:,1,i),points(:,2,i) ,'marker',cell2mat(type(i)),...
              'color',cell2mat(color(i)),...
    'linewidth',4,...
    'markersize',8,...
    'markerfacecolor','w');
   

    
 
    
    
        
end
   axis equal
legend([H([1,2,3,10]);PH],{'Support','C_S_u_p_p_o_r_t','Modulus','start','ER','SF','HIO','DM^-^1^/^β_1_/_β','ASR','HPR','RAAR','HIO_{20}+ER_{1}'},'fontsize',12);



%计算速度和加速度

acceleration = zeros(maxsteps,8);
velocities= zeros(maxsteps+1,8);
for i=1:1:8
   for j=2:1:maxsteps+1
   velocities(j,i) = sqrt(sum((points(j,:,i)-points(j-1,:,i)).^2));
   acceleration(j,i) = velocities(j,i)-velocities(j-1,i);
   
   end
    
end

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






















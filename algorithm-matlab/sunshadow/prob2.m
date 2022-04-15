% 作出附录1时间与影子长度散点图
clear
clc

fid=fopen('mystudy\\附录1.txt');
T=textscan(fid,'%d:%d %f %f');
[T_row,~]=size(T{1,3});
shadowlength = sqrt(T{3}.^2+T{4}.^2)';
time_s = ones(1,T_row);
for i=1:T_row
    time_s(i)=double(T{1}(i))+double(T{2}(i))/60;
end
% %时间坐标
% xtick = time_s(1):6:time_s(T_row);
% [~,c]=size(xtick);
% xticklabel=cell(1,c);
% for i=1:c   
%     xticklabel{i}=sprintf('%02d:%02d',floor((xtick(i)+880)./60),mod((xtick(i)+880),60));
% end
% 多项式拟合
[p,s] = polyfit(time_s,shadowlength,2)
y1=polyval(p,time_s);
figure
plot(time_s,shadowlength,'o');
hold on;
plot(time_s,y1,'b');
hold off;
xlabel('时刻/h');
ylabel('影子长度/m');
title('影子长度随时刻变化曲线');
% set(gca,'XTick',xtick);
% set(gca,'XTicklabel',xticklabel);
% axis([0 65 1 2]);
box off;
%遍历求纬度
%已经求得经度并算得与北京时间相差-0.6小时

time_s=(time_s-0.6-12)*15;
min_sumdistance=1e30;
flag=0;
flag_1=0;
for i=-90:0.01:90
    %计算sumdistance
    sumdistance=0;
    flag_1=0;
    for j=1:T_row 
        for k=j+1:T_row
           distance = cptdistance(108,degtorad(i,0,0),degtorad(time_s(1,j),0,0),degtorad(time_s(1,k),0,0),shadowlength(1,j),shadowlength(1,k));       
           if distance==-1
               flag_1=1;
               break
           end
           sumdistance=sumdistance+distance;
  
        end
    end
    if sumdistance<min_sumdistance && flag_1==0
        min_sumdistance=sumdistance;  
        flag=i;
    end
    
end
flag


        
        



    
    

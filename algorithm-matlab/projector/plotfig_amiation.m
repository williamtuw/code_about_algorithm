function [ ] = plotfig_amiation( points,constraint_ps,constra_ps_style,legends,start,N ,beta,maxsteps)
%��ͼ����

%legends  Ϊ��Ӧconstraint_ps��ͼ��



%8���㷨�Ĺ켣��ʽ  ˳��Ϊ'ER','SF','HIO','DM^-^1^/^��_1_/_��','ASR','HPR','RAAR','HIO_{20}+ER_{1}
color ={'r','g','b','y','m','c','k',[0.8,0.6,0.3]};
type = {'<','>','^','v','s','d','+','o'};

n = length(constraint_ps);


figure
hold on
title(['��=',num2str(beta)],'fontsize',14);
 axis equal
 axis off
% Լ���� (S,M,Sbar,C)
for i=1:1:n
    ps = cell2mat(constraint_ps(i));
    H(i) = plot(ps(:,1),ps(:,2),cell2mat(constra_ps_style(i)),'linewidth',4);  
end
%��ʼ��
H(n+1)=plot(start(1),start(2),'ko','markersize',10,...
    'markerfacecolor','w');

%��������
for j=1:1:maxsteps-1

    

for i=1:1:8
     
     PH(i) = plot(points(j:j+1,1,i),points(j:j+1,2,i) ,'marker',cell2mat(type(i)),...
              'color',cell2mat(color(i)),...
    'linewidth',4,...
    'markersize',8,...
    'markerfacecolor','w');
   
end
%legend([H(1:1:length(legends)),H(n+1),PH],[legends,{'start','ER','SF','HIO','DM^-^1^/^��_1_/_��','ASR','HPR','RAAR','HIO_{20}+ER_{1}'}],'fontsize',12);


mov(j)=getframe();

%ת��gifͼƬ,ֻ����256ɫ
    im = frame2im(mov(j));
    [I,map] = rgb2ind(im,256);
    %д�� GIF89a ��ʽ�ļ�    
    if j== 1;
        imwrite(I,map,'multi.gif','GIF', 'Loopcount',inf,'DelayTime',0.15);
    else
        imwrite(I,map,'multi.gif','GIF','WriteMode','append','DelayTime',0.15);
    end    
    
    

end

movie(mov,20,5);
end



% %���̫��Ӱ�ӳ�����ʱ��ı仯���� 
% 
% clear;clc;
% t = 9:0.01:15;
% t0 = t - 8;
% L = 3;
% Shadowlength = cptShadowlength(L,cptElevation(cptDeclination(295),degtorad(39,54,26),degtorad(cptTkunpunished(t0,116.3),0,0)));
% [min_length,I] = min(Shadowlength);
% disp([min_length,t(I)]);
% plot(t,Shadowlength);
% xlabel('����ʱ��');
% ylabel('Ӱ�ӳ���/m');
% title('Ӱ�ӳ�����ʱ��仯����');

% ���̫��Ӱ�ӳ�����γ�ȵı仯����

% clear
% clc
% L = 3;
% la = -90:0.01:90;
% Shadowlength = cptShadowlength(L,cptElevation(cptDeclination(295),degtorad(la,0,0),degtorad(cptTk(12-8,116.3,295),0,0)));
% Shadowlength(Shadowlength>10) = 10;
% Shadowlength(Shadowlength<0) = 0;
% [min_length,I] = min(Shadowlength);
% disp([min_length,la(I)]);
% plot(la,Shadowlength,'.');
% xlabel({'γ��/��','��γΪ������γΪ��'});
% ylabel('Ӱ�ӳ���/m');
% title('Ӱ�ӳ�����γ�ȱ仯����');
% axis ([-90 90 0 10])

% ���̫��Ӱ�ӳ����뾭�ȵı仯����

clear
clc
L = 3;
lo = -180:0.1:180;
Shadowlength = cptShadowlength(L,cptElevation(cptDeclination(295),degtorad(39,54,26),degtorad(cptTkunpolished(12-8,lo),0,0)));
Shadowlength(Shadowlength>10) = 10;
Shadowlength(Shadowlength<0) = 0;
[min_length,I] = min(Shadowlength);
disp([min_length,lo(I)]);
plot(lo,Shadowlength,'.');
xlabel({'����/��','����Ϊ��������Ϊ��'});
ylabel('Ӱ�ӳ���/m');
title('Ӱ�ӳ����澭�ȶȱ仯����');
axis ([-180 180 0 10])

%���̫��Ӱ�ӳ��������ڵı仯����

% clear
% clc
% date = 1:365;
% L = 3;
% Shadowlength = cptShadowlength(L,cptElevation(cptDeclination(date),degtorad(39,54,26),degtorad(cptTk(12-8,116.3,date),0,0)));
% [min_length,I] = min(Shadowlength);
% disp([min_length,date(I)]);
% plot(date,Shadowlength);
% xlabel({'date','N = 1 ~ 365'});
% ylabel('Ӱ�ӳ���/m');
% axis ([1 365 0 7])
% 
% title('Ӱ�ӳ��������ڱ仯����');
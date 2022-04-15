% %输出太阳影子长度随时间的变化曲线 
% 
% clear;clc;
% t = 9:0.01:15;
% t0 = t - 8;
% L = 3;
% Shadowlength = cptShadowlength(L,cptElevation(cptDeclination(295),degtorad(39,54,26),degtorad(cptTkunpunished(t0,116.3),0,0)));
% [min_length,I] = min(Shadowlength);
% disp([min_length,t(I)]);
% plot(t,Shadowlength);
% xlabel('北京时间');
% ylabel('影子长度/m');
% title('影子长度随时间变化曲线');

% 输出太阳影子长度与纬度的变化曲线

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
% xlabel({'纬度/°','北纬为正，南纬为负'});
% ylabel('影子长度/m');
% title('影子长度随纬度变化曲线');
% axis ([-90 90 0 10])

% 输出太阳影子长度与经度的变化曲线

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
xlabel({'经度/°','东经为正，西经为负'});
ylabel('影子长度/m');
title('影子长度随经度度变化曲线');
axis ([-180 180 0 10])

%输出太阳影子长度与日期的变化曲线

% clear
% clc
% date = 1:365;
% L = 3;
% Shadowlength = cptShadowlength(L,cptElevation(cptDeclination(date),degtorad(39,54,26),degtorad(cptTk(12-8,116.3,date),0,0)));
% [min_length,I] = min(Shadowlength);
% disp([min_length,date(I)]);
% plot(date,Shadowlength);
% xlabel({'date','N = 1 ~ 365'});
% ylabel('影子长度/m');
% axis ([1 365 0 7])
% 
% title('影子长度随日期变化曲线');
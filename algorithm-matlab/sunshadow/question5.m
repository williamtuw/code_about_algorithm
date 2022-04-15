data = xlsread('data');
stickLength = 3.2;
shadowlen = data(:,2);
elevation = atan(stickLength./shadowlen);
% 确定日期 最小化目标函数
d = datestr2d('8/20');
latirange = -90:0.1:90;
longrange = -180:0.1:180;
Error = ones(length(latirange),length(longrange));
t = 12+35/60:0.05:13+32/60;
t0 = t - 8;
for i=1:length(latirange)
    for j=1:length(longrange)
        LATITUDE = latirange(i);
        LONGITUDE = longrange(j);
        
        Ep = cptElevation(cptDeclination(d),degtorad(LATITUDE,0,0),degtorad(cptTk(t0,LONGITUDE,d),0,0));
        Error(i,j) = sum((Ep-elevation').^2);
    end
end
Emin = min(min(Error));
Emax = max(max(Error));
% [r,c] = find(Error==Emin);
% disp(latirange(r));
% disp(longrange(c));
% disp(dtostr(194));
% [Etemp,I] = min(Error,[],3);
Etemp = (Error - Emin)./(Emax-Emin);
% [X,Y] = meshgrid(latirange,longrange);
% Etemp(Etemp > 1e-5)=1e-5;
% surf(X,Y,Etemp');
[r,c] = find(Etemp<1e-6);
result = [latirange(r)' longrange(c)' Etemp(Etemp<1e-6)];
        
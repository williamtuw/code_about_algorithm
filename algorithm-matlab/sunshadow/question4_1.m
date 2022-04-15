data = xlsread('videodata','Sheet2');
stickLength = sqrt(sum((data(1,:)-data(2,:)).^ 2));
shadowlen = sqrt(sum((data(3:end,:)-repmat(data(2,:),length(data(3:end,:)),1)).^2,2));
elevation = atan(stickLength./shadowlen);
% 确定日期 最小化目标函数
d = 194;
latirange = -90:90;
longrange = -180:180;
Error = ones(length(latirange),length(longrange));
t = 8.9:1/30:9+32/60;
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
[X,Y] = meshgrid(latirange,longrange);
Etemp(Etemp > 1e-5)=1e-5;
surf(X,Y,Etemp');
[r,c] = find(Etemp<1e-6);
result = [latirange(r)' longrange(c)' I(Etemp<1e-6) Etemp(Etemp<1e-6)];
        
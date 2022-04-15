data = xlsread('videodata','Sheet2');
stickLength = sqrt(sum((data(1,:)-data(2,:)).^ 2));
shadowlen = sqrt(sum((data(3:end,:)-repmat(data(2,:),length(data(3:end,:)),1)).^2,2));
elevation = atan(stickLength./shadowlen);
% 未知日期 最小化目标函数
d = 1:365;
latirange = -90:90;
longrange = -180:180;
Error = ones(length(latirange),length(longrange),length(d));
t = 8.9:1/30:9+32/60;
t0 = t - 8;
for i=1:length(latirange)
    for j=1:length(longrange)
        for k=1:length(d)
            LATITUDE = latirange(i);
            LONGITUDE = longrange(j);
            D = d(k);
            Ep = cptElevation(cptDeclination(D),degtorad(LATITUDE,0,0),degtorad(cptTk(t0,LONGITUDE,D),0,0));
            Error(i,j,k) = sum((Ep-elevation').^2);
        end
    end
end
[Etemp,I] = min(Error,[],3);
Emax = max(max(Etemp));
Emin = min(min(Etemp));
% [r,c] = find(Etemp==Emin);
% disp(latirange(r));
% disp(longrange(c));
% disp(dtostr(I(Etemp==Emin)));
Etemp = (Etemp - Emin)./(Emax-Emin);
[X,Y] = meshgrid(latirange,longrange);
Etemp(Etemp > 1e-7)=1e-7;
surf(X,Y,Etemp');
[r,c] = find(Etemp<2e-8);
result = [latirange(r)' longrange(c)' I(Etemp<2e-8) Etemp(Etemp<2e-8)];



        
clear; clc;
data = xlsread('附件1-3', '附件2');
len = sqrt(data(:,2) .^2 + data(:,3) .^2)';
X = data(:,2);
Y = data(:,3);
left=1:ceil(length(len)/2);
right=ceil(length(len)/2):length(len);

DIFA = acos( ( X(left) .* X(right) + Y(left) .* Y(right) )' ./ ( len(left) .* len(right) ) );

latitude=degtorad(-90:90,0,0);
longitude=degtorad(-180:180,0,0);

d = 1:365;
rateL=len(left)./len(right);
ErrorL=zeros(length(latitude),length(longitude),length(d));
ErrorA=zeros(length(latitude),length(longitude),length(d));

T = 12.7:0.05:13.7;
T0=T-8;
for k=1:length(d)
    for i=1:length(latitude)
        for j=1:length(longitude)
            D=d(k);
            LATITUDE=latitude(i);
            LONGITUDE=longitude(j);

            TL=degtorad(cptTk(T0(left),LONGITUDE*180/pi,D),0,0);
            TR=degtorad(cptTk(T0(right),LONGITUDE*180/pi,D),0,0);

            EL=cptElevation(cptDeclination(D),LATITUDE,TL);
            ER=cptElevation(cptDeclination(D),LATITUDE,TR);

    %         排除無效值 
            [r,~]=find(EL<0);
            [r_,~]=find(ER<0);
            if ~ isempty(r) || ~isempty(r_)
                ErrorL(i,j,k)=1;
                ErrorA(i,j,k)=1;
                continue;
            end

            AL=cptAzimuth(cptDeclination(D),LATITUDE,TL,EL);
            AR=cptAzimuth(cptDeclination(D),LATITUDE,TR,ER);

            ErrorL(i,j,k)=sum( (tan(ER)./tan(EL)-...
                rateL).^2) ;
            ErrorA(i,j,k)=sum( (abs(AL-AR)-DIFA).^2) ;
        end
    end
end
Lmin=min(min(min(ErrorL)));
Lmax=max(max(max(ErrorL)));
% n=find(ErrorL<=1.01*Lmin);
% Amin = min(min(ErrorA(n)));
%  [r,c]=find(ErrorA==Amin);
% disp(latitude(r)*180/pi);
% disp(longitude(1+mod(c-1,length(longitude)))*180/pi);
% disp(d(ceil((c-1)/length(longitude))));
%计算可能结果
[Temp,test] = min(ErrorL,[],3);
Temp=(Temp-min(min(Temp)))./(max(max(Temp))-min(min(Temp)));
[X,Y]=meshgrid(-90:90,-180:180);
Temp(Temp>0.000001)=0.000001;
surf(X,Y,Temp');
acc = 1e-7;
[a,b] = find(Temp < acc);
a = a - 91;
b = b - 181;
c = [a b test(Temp < acc) Temp(Temp < acc)];


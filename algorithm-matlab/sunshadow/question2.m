clear; clc;
data = xlsread('附件1-3', '附件1');
len = sqrt(data(:,2) .^2 + data(:,3) .^2)';
X = data(:,2);
Y = data(:,3);
left=1:ceil(length(len)/2);
right=ceil(length(len)/2):length(len);

DIFA = acos( ( X(left) .* X(right) + Y(left) .* Y(right) )' ./ ( len(left) .* len(right) ) );

latitude=degtorad(-90:90,0,0);
longitude=degtorad(-180:180,0,0);
d=108;
rateL=len(left)./len(right);
ErrorL=zeros(length(latitude),length(longitude));
ErrorA=zeros(length(latitude),length(longitude));

T = 14.7:0.05:15.7;
T0=T-8;

for i=1:length(latitude)
    for j=1:length(longitude)
        LATITUDE=latitude(i);
        LONGITUDE=longitude(j);
        
        TL=degtorad(cptTk(T0(left),LONGITUDE*180/pi,d),0,0);
        TR=degtorad(cptTk(T0(right),LONGITUDE*180/pi,d),0,0);
        
        EL=cptElevation(cptDeclination(d),LATITUDE,TL);
        ER=cptElevation(cptDeclination(d),LATITUDE,TR);      
%         排除無效值 
        [r,~]=find(EL<0);
        [r_,~]=find(ER<0);
        if ~ isempty(r) || ~isempty(r_)
            ErrorL(i,j)=1;
            ErrorA(i,j)=1;
            continue;
        end
        AL=cptAzimuth(cptDeclination(d),LATITUDE,TL,EL);
        AR=cptAzimuth(cptDeclination(d),LATITUDE,TR,ER);
        
        ErrorL(i,j)=sqrt(sum( (tan(ER)./tan(EL)-...
            rateL).^2) );
        ErrorA(i,j)=sqrt(sum( (abs(AL-AR)-DIFA).^2) );
    end
end

Lmin=min(min(ErrorL));
Lmax=max(max(ErrorL));
% ErrorL=(ErrorL-Lmin)./(Lmax-Lmin);
[la,lo]=find((ErrorL-Lmin)<0.0015);
disp(latitude(la)*180/pi);
disp(longitude(lo)*180/pi);
disp(ErrorL((ErrorL-Lmin)<2e-6)');
% 
% Amin = min(min(ErrorA(la,lo)))
% [la,lo]=find(ErrorA==Amin);
% disp(latitude(la)*180/pi);
% disp(longitude(lo)*180/pi);
% for i=2:length(latitude)-1
%     for j=2:length(longitude)-1
%         if ~(ErrorL(i,j)<=ErrorL(i-1,j)&&ErrorL(i,j)<=ErrorL(i+1,j)...
%                 &&ErrorL(i,j)<=ErrorL(i,j+1)&&ErrorL(i,j)<=ErrorL(i,j-1))
%             ErrorL(i,j)=1;
%         end
%     end
% end
% Lmin=min(min(ErrorL));
% [la,lo]=find((ErrorL-Lmin)<2e-6);
% disp(latitude(la)*180/pi);
% disp(longitude(lo)*180/pi);
% disp(ErrorL((ErrorL-Lmin)<2e-6)');
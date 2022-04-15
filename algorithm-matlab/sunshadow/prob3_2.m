% 依据附录2数据判断位置和日期
clear
clc

data = xlsread('附件1-3', '附件2');
shadowlength = sqrt(data(:,2) .^2 + data(:,3) .^2)';
time_s = 14.7:0.05:15.7;
ErrorL=zeros(181,361,365);
ErrorA=zeros(181,361,365);
ErrorL(:)=1;
ErrorA(:)=1;

latitude=degtorad(-90:90,0,0);
longitude=degtorad(-180:180,0,0);
d = 1:365;
flag_1=0;
for n=1:365 
    for i=-90:90
        for j=-180:180
        %计算sumdistance           
            sumdistance=0;
            flag_1=0;
            for k=1:10                
                distance = cptdistance(n,degtorad(i,0,0),degtorad((mod((j-120)/15+time_s(1,k)+24,24)-12)*15,0,0),...
                    degtorad((mod((j-120)/15+time_s(1,k+10)+24,24)-12)*15,0,0),shadowlength(1,k),shadowlength(1,k+10));       
                if distance==-1
                    flag_1=1;
                    break
                end
                sumdistance=sumdistance+distance;               
            end
            if   flag_1==0
                 ErrorL(i+91,j+181,n)=sumdistance;
                    
            end

        end
    end
end
Lmin=min(min(min(ErrorL)));
Lmax=max(max(max(ErrorL)));
% ErrorL=(ErrorL-Lmin)./(Lmax-Lmin);
[r,c]=find(ErrorL==Lmin);
disp(latitude(r)*180/pi);
disp(longitude(1+mod(c-1,length(longitude)))*180/pi);
disp(d(ceil((c-1)/length(longitude))));


        
        



    
    

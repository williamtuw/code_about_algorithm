% 依据附录2数据判断位置和日期
clear
clc

data = xlsread('附件1-3', '附件3');
shadowlength = sqrt(data(:,2) .^2 + data(:,3) .^2)';
time_s = 14.7:0.05:15.7;


min_sumdistance=1e30;
flagi=0;
flagn=0;
flagj=0;
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
            if sumdistance<min_sumdistance && flag_1==0
                min_sumdistance=sumdistance;  
                flagi=i;
                flagj=j;
                flagn=n;      
            end

        end
    end
end
flagi
flagj
flagn


        
        



    
    

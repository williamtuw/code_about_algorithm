function [ Azimuth ] = cptAzimuth( declination,latitude, tk,elevation )
%compute Azimuth 
%��λ�黡��
Azimuth=acos((sin(declination)*cos(latitude)...
-cos(declination)*sin(latitude)*cos(tk)./cos(elevation)));
end


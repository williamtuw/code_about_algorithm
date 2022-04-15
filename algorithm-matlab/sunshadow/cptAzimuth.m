function [ Azimuth ] = cptAzimuth( declination,latitude, tk,elevation )
%compute Azimuth 
%†ÎÎ»žé»¡¶È
Azimuth=acos((sin(declination)*cos(latitude)...
-cos(declination)*sin(latitude)*cos(tk)./cos(elevation)));
end


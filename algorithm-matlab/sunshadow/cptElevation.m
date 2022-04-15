function [ elevation ] = cptElevation( declination ,latitude,tk  )
% 计算太阳高度角 单位 弧度
%   declination太阳赤纬角,latitude纬度,tk当地时角
elevation = asin(sin(latitude).*sin(declination)...
    +cos(latitude).*cos(declination).*cos(tk));
end


function [ elevation ] = cptElevation( declination ,latitude,tk  )
% ����̫���߶Ƚ� ��λ ����
%   declination̫����γ��,latitudeγ��,tk����ʱ��
elevation = asin(sin(latitude).*sin(declination)...
    +cos(latitude).*cos(declination).*cos(tk));
end


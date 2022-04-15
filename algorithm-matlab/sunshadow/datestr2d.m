function [ d ] = datestr2d( datestring )
%datestr to d
d = datenum(['2015/',datestring,],'yyyy/mm/dd')-datenum(2015,1,1)+1;
end


function [ tk ] = cptTkunpunished( tk0,longitude)
% 计算tk当地时角单位为度
%latitude单位为度
tk=15*(mod(tk0+longitude/15+48,24)-12);
end


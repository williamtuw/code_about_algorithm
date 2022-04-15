function [ rad ] = degtorad( degree ,minnue,second)
% degree to rad
degree_deg = degree + minnue./60 + second./3600;
rad = degree_deg*pi/180;
end


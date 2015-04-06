function [ y] = changeRange(x,l, u, lb, ub )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%#codegen

y = (ub*(x - l) + lb*(u-x))/(u-l);

end



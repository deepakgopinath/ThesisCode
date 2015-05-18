function [ y] = changeRange(x,l, u, lb, ub )
% THis function is used to change the range of the position profile. The
% simulation uses real world units. 

%x - is the position profile
%l - source lower bound
%u - source upper bound
%lb - target lower bound
%ub - target upper bound
%#codegen

y = (ub*(x - l) + lb*(u-x))/(u-l);
end



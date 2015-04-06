function [yy] = smoothDataVec
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

fs = 1000;
totalTime = 20;
y = positionProfile.signals.values;
yL = length(y);
x = 0:(totalTime/(yL-1)):totalTime;
% interpolate
xx = 0:(1/fs):totalTime;
yy = cosineint(x,y,xx);
end


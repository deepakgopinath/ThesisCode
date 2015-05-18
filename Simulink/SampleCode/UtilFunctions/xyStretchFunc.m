function [y] = xyStretchFunc(x, xStretchFactor, yStretchFactor)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

%Script to scaled the position profile along the X and y axis. 
%The amount of scaling is specified as stretch factors. Typically this is
%used only for scaling along the x axis. For Y axis use changeRange
%directly by providing the upper and lower bounds of the destination
%target. 

originalLength = length(x);
targetLength = ceil(xStretchFactor*originalLength);
yStretchMult = yStretchFactor*ones(targetLength,1);
incr = originalLength/targetLength;

y = zeros(targetLength, 1);
idx = 1;

for i=1:targetLength;
    lowerIdx = floor(idx);
    frac = idx - lowerIdx;
    higherIdx = min(ceil(idx), originalLength);
    y(i) = (x(higherIdx)*frac + x(lowerIdx)*(1-frac))*yStretchMult(i) + min(x)*(1 - yStretchFactor);
    idx = idx + incr;
    if(idx > originalLength)
        break;
    end
end

end


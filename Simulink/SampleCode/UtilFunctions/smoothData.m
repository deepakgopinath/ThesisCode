fs = 1000;
totalTime = 20;
y = positionProfile.signals.values;
yL = length(y);
x = 0:(totalTime/(yL-1)):totalTime;
% interpolate
xx = 1:(1/fs):totalTime;
yy = spline(x,y,xx);
plot(x,y,'r',xx,yy,'-');



x = -2500:1:2500;
startP = -0.2623;
endP = 0;

mass = 0.037;
A = -(startP-endP)/2; B = (endP + startP)/2;

y = -A + (2*A)./(1 + exp(-0.01*x)) + B;

fs= 1000;
totalTime = 8;
xx = 0:(1/fs):totalTime;
% offset = 2500;
% yMod = [-0.2623*ones(offset,1)' y(1:length(y) - offset)];
% y(1:2001) = [];
% yMod = [y zeros(3000,1)'];


yMod = changeRange(y, -0.2623, 0, -0.9, 0.6);
yMod(end) = [];
restoreProfile.time = xx;
restoreProfile.signals.values = yMod';
restoreProfile.signals.dimensions = 1;
plot(yMod);
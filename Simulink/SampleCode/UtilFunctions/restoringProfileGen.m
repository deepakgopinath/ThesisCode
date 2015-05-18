%Generate a smooth sigmoid shaped restoring profile which will appended to
%the end of the stroke. 



x = -2500:1:2500; %length of the stroke is 5 seconds
startP = -0.2623; %lowest position of the stroke - drumhead position
endP = 0; %highest position

mass = 0.037;

A = -(startP-endP)/2; B = (endP + startP)/2; %offset stuff

y = -A + (2*A)./(1 + exp(-0.01*x)) + B; %the scaled and shifted sigmoid

fs= 1000; %sample rate for simulation
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
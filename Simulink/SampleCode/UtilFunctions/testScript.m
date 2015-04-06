x = -10:1:10;

startP = -0.2623;
endP = 0;

mass = 0.037;
A = -(startP-endP)/2; B = (endP + startP)/2;

y = -A + (2*A)./(1 + exp(-200*x)) + B;
yN = -A + (2*A)./(1 + exp(-30*x)) + B;
yVel= diff(y);
yAccel = diff(yVel);
figure;
subplot(3,1,1);plot(y); %hold on; plot(yN,'r');
subplot(3,1,2);plot(yVel);%hold on; plot(diff(yN),'r');
subplot(3,1,3); plot(yAccel/0.01);%hold on; plot(diff(diff(yN)), 'r');


fs= 1000;
yL = length(y);
yVelL = length(yVel);
yAccelL = length(yAccel);
totalTime = 10;
x = 0:(totalTime/(yL-1)):totalTime;
xVel = 0:(totalTime/(yVelL-1)):totalTime;
xAccel = 0:(totalTime/(yAccelL-1)):totalTime;
xx = 0:(1/fs):totalTime;
yy = spline(x,y,xx);
yyVel = spline(xVel, yVel,xx);
yyAccel = spline(xAccel,yAccel,xx);
figure;
plot(x,y,'r',xx,yy,'-');
figure;
plot(xVel,yVel,'r',xx,yyVel,'-');
figure;
plot(xAccel,yAccel,'r',xx,yyAccel,'-');

% yyAccelTemp = [zeros(1000,1); yyAccel'];
dataVec.time = xx;
dataVec.signals.values = yy(1:10001)';
dataVec.signals.dimensions = 1;

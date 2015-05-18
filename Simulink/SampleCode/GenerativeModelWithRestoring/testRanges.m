x = restoreProfile.signals.values;
plot(x);
hold on;
stretchx = xyStretchFunc(x,0.5, 1.0);
plot(stretchx,'g');
newx = changeRange(stretchx, -0.2623, 0, 0.2, 0.3);
plot(newx, 'r');

figure;
x = restoreProfile.signals.values;
plot(x);
hold on;
newx = changeRange(x, -0.2623, 0, 0.5, 0.3);
plot(newx, 'g');
stretchx = xyStretchFunc(newx,0.5, 1.0);
plot(stretchx, 'r');




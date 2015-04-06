curve = posProfile.signals.values;
curve = curve(1:4000);
l = -0.2623; u = 0;
lb = -0.9; ub = 0.6; %destination ranges for start and end position. 
curveExpanded = (ub*(curve - l) + lb*(u-curve))/(u-l);
subplot(2,1,1);plot(curve);subplot(2,1,2)
plot(curveExpanded);
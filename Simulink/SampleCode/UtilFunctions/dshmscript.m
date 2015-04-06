clc;
x = posProfile.signals.values;
minx = min(x);

diffT = diff(find(x == minx));
diffT(diffT == 1) = [];
diffT = diffT*0.005;
diffT'
diff(diffT')
figure;
plot(diffT)
hold on;
x = armmodeloutput.signals.values;
minx = min(x);

% diffT = diff(find(x == minx));
% diffT(diffT == 1) = [];
% diffT = diffT*0.005;
% diffT'
% diff(diffT')
% plot(diffT,'r')
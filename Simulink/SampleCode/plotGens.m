% figure;
% h = scatter(0,2,'x');
% 
% title('k vs d phase plot');
% xlim([-3,3]);
% ylim([-3,3]);
% xL = xlim;
% yL = ylim;
% line([0 0], yL);  %x-axis
% line(xL, [0 0]);  %y-axis
% xlabel('damping coefficient - not to scale');
% ylabel('k/m - not to scale');
% set(h, 'SizeData', 205);
% % set(h, 'Color', 'w');
% set(h, 'MarkerEdgeColor', [1 0 0]);


x = pProfile.signals.values;
y = dProfile.signals.values;
plot(x);
plot(y);

scatter(x,-y,'.');
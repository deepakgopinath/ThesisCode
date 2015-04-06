position = posProfile.signals.values;
velocity = velProfile.signals.values;
diffPosition = diff(position);
diffPosition(diffPosition == 0) = [];


position(length(diffPosition): end)= []; %remove trailing zeros. neede for midi sound. 
velocity(length(diffPosition): end) = []; 

position = position'; velocity = velocity';
position(position ~= -0.2623) = 0;
position(position ~= 0) = 1;

num = 1:length(position);
posVel = [num; position; velocity];
fid = fopen('posVel.txt','w');
fprintf(fid, '%5d, %6.4f %6.4f;\n', posVel);
fclose(fid);

velocityMax = velocity(min(find(position == 1)));
velocityMin = velocity(max(find(position == 1)));

fid = fopen('minMax.txt', 'w');
fprintf(fid, '%1d, %6.4f %6.4f;\n', 1, velocityMin, velocityMax);
fclose(fid);

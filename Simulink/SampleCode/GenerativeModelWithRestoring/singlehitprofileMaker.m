x = scaledPositionProfile.signals.values;
[p, loc] = findpeaks(x);

drumHitPosition = -0.9;
mbx = repmat(x(1:loc(1)), 1, 1);

plot(mbx);

newStroke = repmat(mbx, 6, 1);
plot(newStroke);

scalarA = (0:2/length(newStroke):1)'; 
scalarB = (1:-2/length(newStroke):0)';
scalarA(end) = []; scalarB(end) = [];
scalar = [scalarA; scalarB ];
plot(scalar);

scalarXy = xyStretchFunc(scalar, 0.5, 1.0);
hold on; plot(scalarXy, 'r');

adsrStroke = scalarX.*newStroke + (1 - scalarX).*(drumHitPosition);
plot(adsrStroke)


% 0.013cm, cor = -0.88 otherprofiles 1

%single hit profile
% angleProfile = yMod;
% Fs = 1000;
% snipLength = loc(1);
% angleProfile = angleProfile(1:snipLength*Fs);
% plot(angleProfile);
% fid = fopen('SingleHitProfile.txt','w');
% fprintf(fid, '%6.4f\n', mbx);
% fclose(fid);

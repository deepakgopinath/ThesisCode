


profile = posProfile.signals.values;
Fs = 1000; %Sampling rate is 1000Hz. 
snipLength = 8;
profileSnip = profile(1:snipLength*Fs);
plot(profileSnip);

yStretchFactor = 2.3;
xStretchFactor = 1.34;

%Stretching along x axis, same concept as wavetable synthesis.

originalLength = length(profileSnip);
targetLength = xStretchFactor*originalLength;
yStretchMult = yStretchFactor*ones(targetLength,1);
incr = originalLength/targetLength;

finalOutput = zeros(targetLength, 1);
idx = 1;
for i=1:targetLength;
    
    lowerIdx = floor(idx);
    frac = idx - lowerIdx;
    higherIdx = min(ceil(idx), length(profileSnip));
    finalOutput(i) = (profileSnip(higherIdx)*frac + profileSnip(lowerIdx)*(1-frac))*yStretchMult(i) + min(profileSnip)*(1 - yStretchFactor);
    idx = idx + incr;
    if(idx >= length(profileSnip))
        break;
    end
end


% finalOutput = finalOutput.*yStretchMult;
% finalOutput = finalOutput + (min(profileSnip) - min(finalOutput));
hold on;
plot(finalOutput,'r');

% plot(velProfile.signals.values);hold on; plot(diff(finalOutput),'r');
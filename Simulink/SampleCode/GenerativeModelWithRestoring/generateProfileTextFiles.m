%Script to generate text files containing the position profiles for
%different kinds of stroke. To be executed after the model is run. This
%will ensure that scaledPositionProfile will have the necessary position
%profile. 

angleProfile = scaledPositionProfile.signals.values;
% angleProfile = yMod;
Fs = 1000;
snipLength = 5;
angleProfile = angleProfile(1:snipLength*Fs);
plot(angleProfile);
fid = fopen('HL1vel0pos2n.txt','w');
fprintf(fid, '%6.4f\n', angleProfile);
fclose(fid);




%profile1 = SuddenIncrease + Signal1 +Signal2;
%profile2 = No ExternalBounce
%profile3 = Low to High
%profile4 = High to Low + Signal1
 clc;

xTemp = audioread('bounce4.wav');
x = xTemp;

x(length(x) - 44100*3 :length(x))= [];
x(1:44100) = [];
 x(abs(x)<0.02) = 0;
% x(x<0) = 0;
plot(x);

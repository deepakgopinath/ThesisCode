Fs = 1000;
t = 0:1/Fs:1; t(end) =[];
L = length(t);
NFFT = 2^nextpow2(L);
plot(t);
f= 3;
y = sin(2*pi*t*f);plot(y);
ffty = fft(y, NFFT)/L;
f = Fs/2*linspace(0,1,NFFT/2+1);
plot(f,2*abs(ffty(1:NFFT/2+1))) 
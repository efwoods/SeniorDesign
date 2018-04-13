% test the arduino
clear,clc,close all;
tg = xpc;
tg.start; 
%%
[stepper, servo, a] = arduino_setup
% disp('%d', tg.getsignal('Q4 AD'))
pause(1)
test(stepper, servo, tg)


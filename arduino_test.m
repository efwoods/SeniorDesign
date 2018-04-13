% test the arduino
clear,clc,close all;
tg = xpc;
tg.start; 
%%
[stepper, servo] = arduino_setup
% disp('%d', tg.getsignal('Q4 AD'))
test(stepper, servo, tg)

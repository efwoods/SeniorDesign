% test the arduino
clear,clc,close all;
[stepper, servo] = arduino_setup
test(stepper, servo)
% test the arduino
clear,clc,close all;
[stepper, servo] = arduino_setup
weigh_washers(stepper, servo)
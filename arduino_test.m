% test the arduino
% clear,clc,close all;
% build and start the motor control 
simulation_name = 'dc_motor_encoder_hardware_simulated'
% rtwbuild(simulation_name)
hw = struct %hardware
hw.tg=tg;
% hw.S = load(hw.tg,simulation_name)
% hw.tg.start
% hw.tg.status 
[hw.stepper, hw.servo, hw.a] = arduino_setup
pause(1)
test(hw)
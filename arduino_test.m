% test the arduino
clear,clc,close all;
% build and start the motor control 
simulation_name = 'dc_motor_encoder_hardware_simulated'
rtwbuild(simulation_name)
tg=xpc;
load(tg,simulation_name)
tg.start
tg.status 
%%
[stepper, servo, a] = arduino_setup
hw = struct %hardware
hw.stepper= stepper
hw.servo = servo
hw.a = a
hw.tg = tg
% disp('%d', tg.getsignal('Q4 AD'))
pause(1)
% test(hw)
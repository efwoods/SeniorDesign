% test the arduino
clear,clc,close all;
% build and start the motor control 
hw = struct; %hardware
hw.simulation_name = 'dc_motor_encoder_hardware_simulated';
% rtwbuild(hw.simulation_name)
%% 
pause(1) % start the simulink file
hw.tg=tg;
% hw.S = load(hw.tg,hw.simulation_name);
% hw.tg.start
% hw.tg.status
%%
[hw.stepper, hw.servo, hw.a] = arduino_setup
hw.wellLocations = [struct('cw',[-43.2],'ccw',[313.2]);struct('cw',[-64.8],'ccw',[295.2]);struct('cw',[-118.8],'ccw',[241.2]);struct('cw',[-154.8],'ccw',[205.2]);struct('cw',[-194.4],'ccw',[165.6]);struct('cw',[-223.2],'ccw',[136.8]);struct('cw',[-268.2],'ccw',[91.8]);struct('cw',[-289.8],'ccw',[70.2]);struct('cw',[-329.4],'ccw',[30.6]);struct('cw',[-354.6],'ccw',[7.2])];
% rotate_gameboard(hw)
for i = 1:10
    
    x = hw.wellLocations(i).cw
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    pause(1)
end
% rotate ccw
for i = 1:10
    x = hw.wellLocations(i).ccw
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
end
% clockwise is negative
pause(1)
%%


test(hw)
function [sm, s] = arduino_setup
clc
clear
close all
a = arduino('COM5', 'Uno', 'Libraries', 'Adafruit\MotorShieldV2')
disp('arduino initialized')
shield = addon(a, 'Adafruit\MotorShieldV2')
disp('shield initialized')
% addrs = scanI2CBus(a,0)
sm = stepper(shield, 1, 200)
sm.RPM = 10;%      sm.RPM = 50;
disp('stepper initialized')
s = servo(shield, 1)
disp('servo initialized')
%  i = 1;
%  pause(1)
%  writePosition(s, 0);
%  pause(1)
%  writePosition(s, i);
%  pause(1)
%  writePosition(s, 0);
%  pause(1)

% Control stepper motor on the shield

% INNER MOST PENTAGON
%     sm.RPM = 50;
%     move(sm, 50);
%     pause(1);
%     move(sm, -49);
%    release(sm);
disp('setup complete')
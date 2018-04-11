clc 
clear
close all
a = arduino('COM5', 'Uno', 'Libraries', 'Adafruit\MotorShieldV2')
shield = addon(a, 'Adafruit\MotorShieldV2')
addrs = scanI2CBus(a,0)
sm = stepper(shield, 2, 200)
s = servo(shield, 1)
disp('servo')
 i = 1;
 pause(1)
 writePosition(s, 0);
 pause(1)
 writePosition(s, i);
 pause(1)
 writePosition(s, 0);
 pause(1)
%   stepperMotor = stepper(shield, 2, 200);


% Control stepper motor on the shield
% disp('stepper')
% 
% 
%    sm.RPM = 10;
%    move(sm, 80);
%    pause(2);
%    move(sm, -160);
%    release(sm);
%  disp('starting')
%  for count = 1:5
%         stepperMotor.RPM = 20;
%            move(stepperMotor, 50);
%            pause(1);
%          move(stepperMotor, -50);
%          pause(1);
%          disp('continuing')
%  end           
% disp('complete')

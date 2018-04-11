clc
clear
close all
a = arduino('COM5', 'Uno', 'Libraries', 'Adafruit\MotorShieldV2')
shield = addon(a, 'Adafruit\MotorShieldV2')
addrs = scanI2CBus(a,0)
sm = stepper(shield, 1, 200)
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

% Control stepper motor on the shield
 disp('stepper')
 
 % INNER MOST PENTAGON
    sm.RPM = 50;
    move(sm, 50);
    pause(1);
    move(sm, -50);
%    release(sm);
disp('complete')

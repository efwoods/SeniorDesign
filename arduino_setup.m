function [sm, s, a] = arduino_setup
a = arduino('COM5', 'Uno', 'Libraries', 'Adafruit\MotorShieldV2')
disp('arduino initialized')
shield = addon(a, 'Adafruit\MotorShieldV2')
disp('shield initialized')
% addrs = scanI2CBus(a,0)
sm = stepper(shield, 1, 200)
sm.RPM = 10;%      sm.RPM = 50;
disp('stepper initialized')
s = servo(shield, 1)
disp('servo initialized, testing')
  writePosition(s, 0);
%   pause(1)
  writePosition(s, 1);
%   pause(1)
  writePosition(s, 0);
%   pause(1)
% Control stepper motor on the shield
disp('testing stepper motor')

for i = 1:10
     move(sm, 1);
end
%     pause(1);
for i = 1:10
     move(sm, -1);
end
disp('setup and testing complete')
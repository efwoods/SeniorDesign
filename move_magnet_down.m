function move_magnet_down(servoMotor)
disp('Moving Electromagnet DOWNWARDS')
tic
writePosition(servoMotor, 1)
toc
disp('Electromagnet is in the DOWN position')
end
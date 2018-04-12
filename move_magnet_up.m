function move_magnet_up(servoMotor)
disp('Moving Electromagnet UPWARDS')
tic
writePosition(servoMotor, .5)
toc
disp('Electromagnet is in the UP position')
end

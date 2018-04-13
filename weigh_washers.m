function weigh_washers(stepper, servo)
disp('WEIGHING WASHERS BEGIN')
tic
% stepper rotates arm to load cell position 
rotate_from_loadcell_to_innerwell(stepper)
pause(1)
move_magnet_down(servo)
pause(1)
emag_on
pause(1)
move_magnet_up(servo)
pause(1)
rotate_to_loadcell(stepper)
pause(1)
move_magnet_down(servo)
pause(1)
emag_off
% load cell weighs washer
pause(1)
emag_on
pause(1)
move_magnet_up(servo)
pause(1)
rotate_from_loadcell_to_innerwell(stepper)
pause(1)
move_magnet_down(servo)
pause(1)
emag_off
pause(1)
move_magnet_up(servo)
pause(1)
% for testing the arm resets to the load cell
rotate_to_loadcell(stepper)
toc
disp('WEIGHING WASHERS COMPLETE')
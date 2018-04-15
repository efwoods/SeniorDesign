function weigh_washers(hw)
disp('WEIGHING WASHERS BEGIN')
tic
move_magnet_down(hw)
pause(1)
emag_on
pause(1)
move_magnet_up(hw)
pause(1)
rotate_to_loadcell(hw)
pause(1)
[hw.lc.init, hw.lc.load] = loadcell(hw)
disp('init:')

disp(hw.lc.init)
disp('load:')
disp(hw.lc.load)
pause(1)
rotate_from_loadcell_to_innerwell(hw)
 pause(1)
emag_off
toc
disp('WEIGHING WASHERS COMPLETE')
function rotate_from_loadcell_to_innerwell(stepperMoter)
disp('Moving to Inner Well')
tic
move(stepperMoter, -49);
toc
disp('Arrived at Inner Well')
end

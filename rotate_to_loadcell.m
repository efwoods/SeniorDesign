function rotate_to_loadcell(stepperMoter)
disp('Moving to Load Cell')
tic
move(stepperMoter, 50);
toc
disp('Arrived at Load Cell')
end
function rotate_from_loadcell_to_innerwell(stepperMoter)
x = 47
disp('Moving to Inner Well')
tic

for i = 1:x
    move(stepperMoter, -1);
end
toc
disp('Arrived at Inner Well')
end

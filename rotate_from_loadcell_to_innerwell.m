function rotate_from_loadcell_to_innerwell(hw)
x = 47
disp('Moving to Inner Well')
tic

for i = 1:x
    move(hw.stepper, -1);
end
toc
disp('Arrived at Inner Well')
end

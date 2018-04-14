function rotate_to_loadcell(hw)
x = 47
disp('Moving to Load Cell')
tic
for i = 1:x
    move(hw.stepper, 1);
end
toc
disp('Arrived at Load Cell')
end
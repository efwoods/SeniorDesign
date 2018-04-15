function rotate_from_load_cell_to_quick_stop(hw)
x = 18;
disp('ARM MOVING TO LOAD CELL FROM QUICK STOP')
for i = 1:x
    move(hw.stepper, 1)
end
disp('ARM HAS ARRIVED AT LOAD CELL');
end
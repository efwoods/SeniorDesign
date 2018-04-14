function rotate_from_quick_stop_to_load_cell(hw)
x = 22;
disp('ARM MOVING TO LOAD CELL FROM QUICK STOP')
for i = 1:x
    move(hw.stepper, 1)
end
disp('ARM HAS ARRIVED AT LOAD CELL');
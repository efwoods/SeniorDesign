function rotate_from_OUTER_well_to_INNER_well(hw)
x = 7;
disp('ARM MOVING TO LOAD CELL FROM QUICK STOP')
for i = 1:x
    move(hw.stepper, -1)
end
disp('ARM HAS ARRIVED AT LOAD CELL');
end
function rotate_from_INNER_well_to_OUTER_well(hw)
x = 8;
disp('ARM MOVING TO LOAD CELL FROM QUICK STOP')
for i = 1:x
    move(hw.stepper, 1)
end
disp('ARM HAS ARRIVED AT LOAD CELL');
end
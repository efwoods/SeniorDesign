function rotate_from_load_cell_to_outer_well(handles)
x = 44;
disp('ARM MOVING TO LOAD CELL FROM QUICK STOP')
for i = 1:x
    move(handles.stepper, -1)
end
disp('ARM HAS ARRIVED AT LOAD CELL');
end
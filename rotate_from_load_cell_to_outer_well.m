function rotate_from_load_cell_to_outer_well(handles)
x = 41;
disp('ARM MOVING from LOAD CELL to OUTER well')
for i = 1:x
    move(handles.stepper, -1)
end
disp('ARM HAS ARRIVED AT OUTER WELL');
end
function rotate_from_fast_rest_to_load_cell(stepper, servo, tg)
x = 22;
disp('ARM MOVING TO LOAD CELL FROM QUICK STOP')
for i = 1:x
    move(stepper, 1)
end
disp('ARM HAS ARRIVED AT LOAD CELL');
% test.m
function test(stepper, servo)
reset_arm_to_innerwell(stepper)
pause(1)
rotate_to_loadcell(stepper)
pause(1)
weigh_washers(stepper, servo)
pause(1)
rotate_from_loadcell_to_innerwell(stepper)
pause(1)
reset_arm(stepper)
end
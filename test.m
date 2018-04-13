% test.m
function test(stepper, servo, tg)
reset_arm_to_innerwell(stepper)
pause(1)
weigh_washers(stepper, servo, tg)
pause(1)
% pause(1)
reset_arm(stepper)
end
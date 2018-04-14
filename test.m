% test.m
function test(hw)
reset_arm_to_innerwell(hw)
pause(1)
weigh_washers(hw)
pause(1)
% pause(1)
reset_arm(hw)
end
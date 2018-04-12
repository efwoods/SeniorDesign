function reset_arm_to_innerwell(stepper)
% resets arm from inner well

x = 65
disp('ARM RESETTING');
tic
for i = 1:x
    move(stepper, 1)
end
toc
disp('ARM RESET');
end
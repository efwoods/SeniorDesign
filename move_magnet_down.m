function move_magnet_down(hw)
disp('Moving Electromagnet DOWNWARDS')
tic
writePosition(hw.servo, .9)
toc
disp('Electromagnet is in the DOWN position')
end
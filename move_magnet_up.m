function move_magnet_up(hw)
disp('Moving Electromagnet UPWARDS')
tic
writePosition(hw.servo, .5)
toc
disp('Electromagnet is in the UP position')
end

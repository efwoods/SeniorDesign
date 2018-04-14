function move_magnet_up(hw)
disp('Moving Electromagnet UPWARDS')
tic
writePosition(hw.servo, .4)
toc
disp('Electromagnet is in the UP position')
end

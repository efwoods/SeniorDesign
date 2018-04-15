function rotate_gameboard(hw)
% rotate clockwise
for i = 1:10
    x = hw.wellLocations(i).cw
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
end
% rotate ccw
for i = 1:10
    x = hw.wellLocations(i).ccw
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
end
end
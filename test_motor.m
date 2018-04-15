function test_motor(hw)
% load(hw.tg,hw.simulation_name)
max = 360
for x = 0:max
    hw.tg.set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    pause(1)
end
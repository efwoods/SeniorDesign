function  = test_e_stop()
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
 % temporary testing of e_stop
       x = 0;
while(1)
    x = x + 1
    if(x > 360)
            x = 0;
    end
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));    
    pause(1)
end

end


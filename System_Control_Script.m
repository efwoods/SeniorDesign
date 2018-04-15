powered_on_when_above_floor_threshold_weight = 1;
floor_threshold_weight = 5; %% measured in grams
ceiling_threshold_weight = 20;   %% measured in grams

tg = xpc;
tg.start; 

initialReading = tg.getsignal('Q4 AD') %% initial value has been random
max_voltage = 6.70; %% predetermined
scaling_factor = (max_voltage - initialReading)*100/ 35 %% maximum voltage is reached at approximately 35 grams
while(1)
      voltage = tg.getsignal('Q4 AD')
      
      weight = abs(voltage-initialReading) * (scaling_factor) %% weight is measured in grams
      
      %Conditional Logic
      
      if(powered_on_when_above_floor_threshold_weight)
        if(weight > floor_threshold_weight)
            set_param('System/Magnet_Control','Value','1');
        else
            set_param('System/Magnet_Control','Value','0');
        end
      else
            if(weight < ceiling_threshold_weight)
                set_param('System/Magnet_Control','Value','1');
            else
                set_param('System/Magnet_Control','Value','0');
            end
      end 
      pause(.05); % allows time for display to update
end
tg.stop;  % stop the model
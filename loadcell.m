function [initialReading, loadReading] = loadcell(hw)
% floor_threshold_weight = 5; %% measured in grams
% ceiling_threshold_weight = 20;   %% measured in grams

initialReading = hw.tg.getsignal('Q4 AD') %% initial value has been random
%     max_voltage = 6.70; %% predetermined
%     scaling_factor = (max_voltage - initialReading)*100/ 35 %% maximum voltage is reached at approximately 35 grams
    disp('Load Cell: NO LOAD')
    disp(hw.tg.getsignal('Q4 AD'))
% pause(1)
% move_magnet_down(servo)
pause(1)
emag_off
pause(2)
% move_magnet_up(servo)
% pause(1)
disp('Load Cell: LOAD')
loadReading = hw.tg.getsignal('Q4 AD')% load cell weighs washer
% weight = abs(loadReading - initialReading) * (scaling_factor) %% weight is measured in grams
% disp(loadReading)

difference = loadReading - initialReading

while(difference < 0)
    loadReading = hw.tg.getsignal('Q4 AD')% load cell weighs washer
    difference = loadReading - initialReading
end
if(difference >= 0.09)
    disp('3 washer')
elseif((difference < 0.09) && (difference >= 0.04))
    disp('2 washer')
else
    disp('1 washer')
end
disp(difference)
disp(hw.tg.getsignal('Q4 AD'))% load cell weighs washer
 pause(1)
 move_magnet_down(hw)
pause(1)
emag_on
pause(1)
move_magnet_up(hw)
pause(1)
disp('Load Cell: NO LOAD')
disp(hw.tg.getsignal('Q4 AD'))
pause(1)
end
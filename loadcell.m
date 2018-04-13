function [initialReading, loadReading] = loadcell(tg,servo)
% floor_threshold_weight = 5; %% measured in grams
% ceiling_threshold_weight = 20;   %% measured in grams

initialReading = tg.getsignal('Q4 AD') %% initial value has been random
    max_voltage = 6.70; %% predetermined
    scaling_factor = (max_voltage - initialReading)*100/ 35 %% maximum voltage is reached at approximately 35 grams
    disp('Load Cell: NO LOAD')
    disp(tg.getsignal('Q4 AD'))
% pause(1)
% move_magnet_down(servo)
pause(1)
emag_off
pause(1)
% move_magnet_up(servo)
% pause(1)
disp('Load Cell: LOAD')
loadReading = tg.getsignal('Q4 AD')% load cell weighs washer
weight = abs(loadReading - initialReading) * (scaling_factor) %% weight is measured in grams
disp(weight)



disp(tg.getsignal('Q4 AD'))% load cell weighs washer
 pause(1)
 move_magnet_down(servo)
pause(1)
emag_on
pause(1)
move_magnet_up(servo)
pause(1)
disp('Load Cell: NO LOAD')
disp(tg.getsignal('Q4 AD'))
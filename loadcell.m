function [hw] = loadcell(hw)
% floor_threshold_weight = 5; %% measured in grams
% ceiling_threshold_weight = 20;   %% measured in grams

hw.loadcell.initialReading = hw.tg.getsignal('Q4 AD'); %% initial value has been random
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
hw.loadcell.loadReading = hw.tg.getsignal('Q4 AD')% load cell weighs washer
% weight = abs(loadReading - initialReading) * (scaling_factor) %% weight is measured in grams
% disp(loadReading)

hw.loadcell.difference = hw.loadcell.loadReading - hw.loadcell.initialReading;

while(hw.loadcell.difference < 0)
    hw.loadcell.loadReading = hw.tg.getsignal('Q4 AD'); % load cell weighs washer
    hw.loadcell.difference = hw.loadcell.loadReading - hw.loadcell.initialReading;
end
if(hw.loadcell.difference >= 0.09)
    disp('3 washer')
    hw.loadcell.layers = 3;
elseif((hw.loadcell.difference < 0.09) && (hw.loadcell.difference >= 0.04))
    disp('2 washer')
    hw.loadcell.layers = 2;
else
    disp('1 washer')
    hw.loadcell.layers = 1;
end
disp(hw.loadcell.difference)
% disp(hw.tg.getsignal('Q4 AD'))% load cell weighs washer
end
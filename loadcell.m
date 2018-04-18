function [hw] = loadcell(hw)
% floor_threshold_weight = 5; %% measured in grams
% ceiling_threshold_weight = 20;   %% measured in grams

hw.loadcell.initialReading = hw.tg.getsignal('Q4 AD'); %% initial value has been random
    disp('Load Cell: NO LOAD')
    disp(hw.tg.getsignal('Q4 AD'))
pause(.3)
emag_off
pause(.3)
disp('Load Cell: LOAD')
hw.loadcell.loadReading = hw.tg.getsignal('Q4 AD');% load cell weighs washer
disp(hw.loadcell.loadReading)
hw.loadcell.difference = hw.loadcell.loadReading - hw.loadcell.initialReading;

while(hw.loadcell.difference < 0)
    hw.loadcell.loadReading = hw.tg.getsignal('Q4 AD'); % load cell weighs washer
    hw.loadcell.difference = hw.loadcell.loadReading - hw.loadcell.initialReading;
end
if(hw.loadcell.difference >= 0.082)
    disp('3 washer')
    hw.loadcell.layers = 3;
elseif((hw.loadcell.difference < 0.082) && (hw.loadcell.difference >= 0.05))
    disp('2 washer')
    hw.loadcell.layers = 2;
elseif(hw.loadcell.difference < 0.01)
    disp('no washer')
    hw.loadcell.layers = 0;
else
    disp('1 washer')
    hw.loadcell.layers = 1;
end
disp(hw.loadcell.difference)
end
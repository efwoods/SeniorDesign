% test the arduino
% clear,clc,close all;
% build and start the motor control 
hw = struct; %hardware
hw.simulation_name = 'dc_motor_encoder_hardware_simulated';
% rtwbuild(hw.simulation_name)

% pause(1) % start the simulink file
hw.tg=tg;
% hw.S = load(hw.tg,hw.simulation_name);
% hw.tg.start
% hw.tg.status

[hw.stepper, hw.servo, hw.a] = arduino_setup;
hw.wellLocations = [struct('cw',[-43.2],'ccw',[313.2]);struct('cw',[-64.8],'ccw',[295.2]);struct('cw',[-118.8],'ccw',[241.2]);struct('cw',[-154.8],'ccw',[205.2]);struct('cw',[-194.4],'ccw',[165.6]);struct('cw',[-223.2],'ccw',[136.8]);struct('cw',[-268.2],'ccw',[91.8]);struct('cw',[-289.8],'ccw',[70.2]);struct('cw',[-329.4],'ccw',[30.6]);struct('cw',[-354.6],'ccw',[7.2])];
%%
% rotate_gameboard(hw)
start = tic
reset_arm_to_innerwell(hw)
% rotate_from_load_cell_to_outer_well(hw)
% rotate_from_loadcell_to_innerwell(hw)
pause(.3)
for i = 1:10
     if i > 1
     if mod(i,2)==0
         rotate_from_INNER_well_to_OUTER_well(hw)
     else
         rotate_from_OUTER_well_to_INNER_well(hw)
         
     end
     end
    x = hw.wellLocations(i).cw
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    pause(.3)
    move_magnet_down(hw)
    pause(.3)
    emag_on
    pause(.3)
    move_magnet_up(hw)
    pause(.3)
    if mod(i,2)==0
         rotate_from_outer_well_to_load_cell(hw)
         pause(.3)
         emag_off
         pause(.3)
         move_magnet_down(hw)
         pause(.3)
         emag_on
         pause(.3)
         move_magnet_up(hw)
         pause(.3)
         rotate_from_load_cell_to_outer_well(hw)
         pause(.3)
     else
         rotate_to_loadcell(hw)
         pause(.3)
         emag_off
         pause(.3)
         move_magnet_down(hw)
         pause(.3)
         emag_on
         pause(.3)
         move_magnet_up(hw)
         pause(.3)
         rotate_from_loadcell_to_innerwell(hw)
         pause(.3)
     end
    
    
    
    emag_off
    pause(.3)
     end
% rotate_from_outer_well_to_load_cell(hw)
rotate_from_OUTER_well_to_INNER_well(hw)
reset_arm(hw)
stop = toc(start)
%%
% rotate ccw
for i = 1:10
    x = hw.wellLocations(i).ccw
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
end
% clockwise is negative
pause(1)
%%


% test(hw)
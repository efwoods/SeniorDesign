function handles = resetGUI(handles)
    % reset board back to zero degrees
    x = 0;
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value',num2str(x));
    % reset the arm 
    if (handles.armposition == 1) 
                rotate_from_inner_well_to_loadcell(handles);
            elseif (handles.armposition == 2)
                rotate_from_outer_well_to_loadcell(handles);
            else
                disp('at loadcell');
    end
    handles.armposition = 0;
    handles.finalwell = wInit();
    handles.curwell = wInit();
    %1
%     set(handles.pum_Well1Color,'value',1);
%     set(handles.pum_Well1Layer,'value',1);
%     %2
%     set(handles.pum_Well2Color,'value',1);
%     set(handles.pum_Well2Layer,'value',1);
%     %3
%     set(handles.pum_Well3Color,'value',1);
%     set(handles.pum_Well3Layer,'value',1);
%     %4
%     set(handles.pum_Well4Color,'value',1);
%     set(handles.pum_Well4Layer,'value',1);
%     %5
%     set(handles.pum_Well5Color,'value',1);
%     set(handles.pum_Well5Layer,'value',1);
%     %6
%     set(handles.pum_Well6Color,'value',1);
%     set(handles.pum_Well6Layer,'value',1);
%     %7
%     set(handles.pum_Well7Color,'value',1);
%     set(handles.pum_Well7Layer,'value',1);
%     %8
%     set(handles.pum_Well8Color,'value',1);
%     set(handles.pum_Well8Layer,'value',1);
%     %9
%     set(handles.pum_Well9Color,'value',1);
%     set(handles.pum_Well9Layer,'value',1);
%     %10
%     set(handles.pum_Well10Color,'value',1);
%     set(handles.pum_Well10Layer,'value',1);
%     
%     
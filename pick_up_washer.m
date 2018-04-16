function pick_up_washer(handles)
pause(.3)
      move_magnet_down(handles)
      pause(.3)
      open_system(handles.simulation_name);
      set_param('dc_motor_encoder_hardware_simulated/Magnet_Control','Value','10');
      pause(.3)
      move_magnet_up(handles)
      pause(.3)
end
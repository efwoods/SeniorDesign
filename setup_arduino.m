function [hObject, handles] = setup_arduino(hObject, handles)
handles.a = arduino('COM5', 'Uno', 'Libraries', 'Adafruit\MotorShieldV2')
disp('arduino initialized')
handles.shield = addon(handles.a, 'Adafruit\MotorShieldV2')
disp('shield initialized')
% addrs = scanI2CBus(a,0)
handles.stepper = stepper(handles.shield, 2, 200)
handles.stepper.RPM = 10;%      sm.RPM = 50;
disp('stepper initialized')
handles.servo = servo(handles.shield, 1)
disp('servo initialized, testing')
handles.wellLocations = [struct('cw',[-43.2],'ccw',[313.2]);struct('cw',[-64.8],'ccw',[295.2]);struct('cw',[-118.8],'ccw',[241.2]);struct('cw',[-154.8],'ccw',[205.2]);struct('cw',[-194.4],'ccw',[165.6]);struct('cw',[-223.2],'ccw',[136.8]);struct('cw',[-268.2],'ccw',[91.8]);struct('cw',[-289.8],'ccw',[70.2]);struct('cw',[-329.4],'ccw',[30.6]);struct('cw',[-354.6],'ccw',[7.2])];
guidata(hObject, handles);

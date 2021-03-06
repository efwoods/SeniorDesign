function varargout = project4gui(varargin)
% PROJECT4GUI MATLAB code for project4gui.fig
%      PROJECT4GUI, by itself, creates a new PROJECT4GUI or raises the existing
%      singleton*.
%
%      H = PROJECT4GUI returns the handle to a new PROJECT4GUI or the handle to
%      the existing singleton*.
%
%      PROJECT4GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROJECT4GUI.M with the given input arguments.
%
%      PROJECT4GUI('Property','Value',...) creates a new PROJECT4GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before project4gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to project4gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help project4gui

% Last Modified by GUIDE v2.5 17-Apr-2018 23:09:27

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @project4gui_OpeningFcn, ...
                   'gui_OutputFcn',  @project4gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT




% --- Executes just before project4gui is made visible.
function project4gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to project4gui (see VARARGIN)
% Choose default command line output for project4gui
handles.output = hObject;

% data=tg;
% handles.tg=data;
handles.finalwell = wInit();
handles.curwell = wInit();
handles.imagewell = wInit();
handles.simulation_name = 'dc_motor_encoder_hardware_simulated';
handles.magnet = 'dc_motor_encoder_hardware_simulated/Magnet_Control';
handles.loadcell.color = 'None';
handles.loadcell.layers = 0;
handles.loadcell.empty = 1;

guidata(hObject, handles);
% rtwbuild(handles.simulation_name)

handles.tg = xpc;
guidata(hObject, handles);
% load(handles.tg, handles.simulation_name)
% handles.tg.start
% handles.tg.status
% handles.tg = tg;

% load_system(handles.simulation_name)

% load(hw.tg,hw.simulation_name);
% handles.tg.start
% handles.tg.status


%1: xleft xright ytop y bot
%handles.well_pixels =  [405 488 160 240; 405 486 70 140; 285 355 65 138; 156 230 75 143;
%                157 231 171 240; 123 192 280 349; 223 290 320 387; 290 356 383 448; 
 %               348 424 316 384; 448 520 275 346;];
handles.well_pixels = [170 225 250 300; 170 225 350 400; 300 350 350 400; 430 480 340 400;
                430 480 250 300; 460 520 140 190; 360 420 100 150; 300 350 38 88; 230 280 110 160;
                130 190 140 195];
handles.start = 0;
handles.cam = webcam('HP USB Webcam');

% arduino setup
% test the arduino
% clear,clc,close all;
% build and start the motor control 
% hw = struct; %hardware


% Update handles structure

% sim(handles.simulation_name)


% pause(1) % start the simulink file



% hw.tg.status
[hObject, handles] = setup_arduino(hObject, handles);
% UIWAIT makes project4gui wait for user response (see UIRESUME)
%uiwait(handles.figure1);

% Force configuration tables to display 10 rows
initialConfigCol = 2;
initialConfigRow = 10;
finalConfigCol = 3;
finalConfigRow = 10;
set(handles.table_InitialConfiguration,'Data',cell(initialConfigRow,initialConfigCol))
set(handles.table_FinalConfiguration,'Data',cell(finalConfigRow,finalConfigCol))
ti = handles.table_InitialConfiguration;
tf = handles.table_FinalConfiguration;

% populate reference image
reference = imread('WasherMoverReference.png');
axes(handles.axes_reference);
imshow(reference);

guidata(hObject, handles);



% --- Outputs from this function are returned to the command line.
function varargout = project4gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.finalwell;
disp('outing');


% --- Executes on key release with focus on figure1 or any of its controls.
function figure1_WindowKeyReleaseFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.FIGURE)
%	Key: name of the key that was released, in lower case
%	Character: character interpretation of the key(s) that was released
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) released
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pb_ReadBackground.
function pb_ReadBackground_Callback(hObject, eventdata, handles)
% hObject    handle to pb_ReadBackground (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.gb = snapshot(handles.cam);
handles.gb = imrotate(handles.gb,180);
imwrite(handles.gb, 'background.png');
axes(handles.axes_image);
imshow(handles.gb);
guidata(hObject, handles);


% --- Executes on button press in pb_Start.
function pb_Start_Callback(hObject, eventdata, handles)


% if error_all_selected(handles) == 1
%     ed = errordlg('Make sure all selections have layer and color selected', 'Error');
%     set(ed, 'WindowStyle', 'modal');
%     return;
% end

if error_color_check(handles) == 1
    ed = errordlg('Colors read from image do not match colors input in gui', 'Error');
    set(ed, 'WindowStyle', 'modal');
    return;
end

if error_empty_gui(handles) == 1
    ed = errordlg('Nothing set in the gui', 'Error');
    set(ed, 'WindowStyle', 'modal');
    return;
end
    
% hObject    handle to pb_Start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('starting');
% testing case only
disp('testing')
% rotate_from_load_cell_to_outer_well(handles)
handles.checkedwashers = handles.totalwashers;
handles.armposition = 0; 
handles.curwell = handles.imagewell;
% 0 indicates @ loadcell 
% 1 indicates @ innerwell
% 2 indicates @ outerwell

%%
red_on(handles)
green_off(handles)
start_tic = tic;
found = 1;      % indicating if prior match has been made. Initialize to 1 so that we may entire while loop
for i = 1:10                   %% for each well on the gameboard
	found = 1;
    while(found == 1)          %% while still finding matches, continue checking current well
		found = 0;             %% match has yet to be found
		if (handles.curwell(i).correct == 0 && handles.curwell(i).empty == 0)        %% well has not been finalized and contains a washer
			pause(.1)
            x = handles.wellLocations(i).cw;
            %load(handles.tg,handles.simulation_name)
            set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value',num2str(x));
            
            % move arm to desired well location
            if (mod(i,2) == 0)      %% desired well is at outer well, move arm to outer well position
                if (handles.armposition == 0)       %% arm at loadcell
                    rotate_from_load_cell_to_outer_well(handles);
                elseif (handles.armposition == 2)   %% arm already at outer well
                    disp('at position');
                else                                %% arm at inner well
                    rotate_from_INNER_well_to_OUTER_well(handles);
                end
                handles.armposition = 2;
            else                    %% desired well is at inner well, move arm to inner well position
                if (handles.armposition == 0)       %% arm at loadcell
                    rotate_from_loadcell_to_innerwell(handles);
                elseif (handles.armposition == 1)   %% arm already at inner well
                    disp('at position');
                else                                %% arm at outer well
                    rotate_from_OUTER_well_to_INNER_well(handles);
                end
                handles.armposition = 1;
            end
        
            % pick up washer, move to load cell
            pick_up_washer(handles)
            if (handles.armposition == 1) 
                rotate_to_loadcell(handles);
            elseif (handles.armposition == 2)
                rotate_from_outer_well_to_load_cell(handles);
            else
                disp('at loadcell');
            end
            handles.armposition = 0;
            pause(0.3);
            
            % weigh washer, leave washer at load cell.
            handles = loadcell(handles);
            loadcount = 0;
%             while(handles.loadcell.layers == 0)
%                 loadcount = loadcount + 1;
%                    if (mod(i,2) == 0)      % final position at outer well
%                             rotate_from_load_cell_to_outer_well(handles);
%                             move_magnet_down(handles);
%                             pause(0.2);
%                             emag_on;
%                             pause(0.2);
%                             move_magnet_up(handles);
%                             pause(0.2);
%                             handles.armposition = 2;
%                             rotate_from_outer_well_to_load_cell(handles);
%                             pause(0.2);
%                             emag_off;
%                             pause(0.2);
%                             handles = loadcell(handles);
%                         else                    % final position at inner well
%                             rotate_from_loadcell_to_innerwell(handles);
%                             move_magnet_down(handles);
%                             pause(0.2);
%                             emag_on;
%                             pause(0.2);
%                             move_magnet_up(handles);
%                             pause(0.2);
%                             handles.armposition = 1;
%                             rotate_to_loadcell(handles);
%                             pause(0.2);
%                             emag_off;
%                             handles = loadcell(handles);
%                    end
%                    if loadcount == 5
%                        break;
%                    end
%             end       
%             handles.armposition = 0;
                
            pause(0.3);
            
            % move washer info from current well to loadcell well
            handles.loadcell.color = handles.curwell(i).color;
%             handles.loadcell.layers = handles.curwell(i).layers;
            handles.loadcell.empty = handles.curwell(i).empty;
            handles.curwell(i).color = 'None';
            handles.curwell(i).layers = 0; %added char '
            handles.curwell(i).empty = 1;
            
            % for each well in desired final position matrix that is NOT finalized
            for j = 1:10
                if ((found == 0) && (handles.curwell(j).correct ==0))     % match has yet to be found in final matrix and final matrix is not finalized
                	if (strcmp(handles.finalwell(j).color,handles.loadcell.color) && (str2num(handles.finalwell(j).layers) == handles.loadcell.layers))
                        found = 1;  % match is found, previous match has not been made
                        if (handles.curwell(j).empty == 0)    % well is not empty; move contents in the well out
                            
                            % move washer from final well position to current well position
                            % rotate to final well position
                            x = handles.wellLocations(j).cw;
                            set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value',num2str(x));
                            
                            % move arm to final well position; pick up washer
%                             if(handles.armposition == 0)
                                if (mod(j,2) == 0)  % final well is an outer well
                                    rotate_from_load_cell_to_outer_well(handles);
                                    handles.armposition = 2;
                                else                % final well is an inner well
                                    rotate_from_loadcell_to_innerwell(handles);
                                    handles.armposition = 1;
                                end
                            
                            %pickup j move to i
                            pick_up_washer(handles);
                            pause(.3);
                            % rotate to current well position
                            x = handles.wellLocations(i).cw;
                            set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value',num2str(x));
                            
                            % move arm to current well position; drop washer
                            if ((mod(j,2) == 0) && mod(i,2) == 0) || (mod(j,2) == 0  && mod(i,2) == 0) % arm is at correct inner/outer well position
                                disp('at correct well position');
                            elseif ((mod(j,2) == 0) && (mod(i,2) == 1)) % arm must move from outer to inner
                                rotate_from_OUTER_well_to_INNER_well(handles);
                                handles.armposition = 1;
                            elseif ((mod(j,2) == 1) && (mod(i,2) == 0))   % arm must move from inner to outer
                                rotate_from_INNER_well_to_OUTER_well(handles);
                                handles.armposition = 2;
                            end
                            pause(.5)
                            emag_off;
                            pause(.3)
                                
                            % move washer info from final well position to current well position
                            handles.curwell(i).color = handles.curwell(j).color;
                            handles.curwell(i).layers = handles.curwell(j).layers;
                            handles.curwell(i).empty = handles.curwell(j).empty;
                            
                            % move arm to load cell
                            if (mod(i,2) == 0)  % arm is at outer well
                                rotate_from_outer_well_to_load_cell(handles);
                                
                            else                % arm is at inner well
                                rotate_to_loadcell(handles);
                            end
                            handles.armposition = 0;
                        end
                        
                        % move washer from loadcell to final well
                        % rotate to final position
                        x = handles.wellLocations(j).cw;
                        set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value',num2str(x));
                        
                        % pick up washer, move to final position
                        pick_up_washer(handles);
                        if (mod(j,2) == 0)      % final position at outer well
                            rotate_from_load_cell_to_outer_well(handles);
                            handles.armposition = 2;
                        else                    % final position at inner well
                            rotate_from_loadcell_to_innerwell(handles);
                            handles.armposition = 1;
                        end
                        
                        pause(.2)
                        emag_off;
                        pause(.2)
                        
                        x = handles.wellLocations(i).cw; 
                        set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value',num2str(x)); 
%                         drive by
                        
                        
                        % move washer info from load cell to final well position
%%                        curwell needs to be updated not final well
%                         handles.finalwell(j).color = handles.loadcell.color;
%                         handles.finalwell(j).layers = handles.loadcell.layers;
%                         handles.finalwell(j).empty = handles.loadcell.empty;
%                         handles.finalwell(j).correct = 1;
                         handles.curwell(j).color = handles.loadcell.color;
                         handles.curwell(j).layers = handles.loadcell.layers;
                         handles.curwell(j).empty = handles.loadcell.empty;
                         handles.curwell(j).correct = 1;
                       
                    end
                end
            end
        end
    end
end
if (handles.armposition == 1) 
                rotate_to_loadcell(handles);
            elseif (handles.armposition == 2)
                rotate_from_outer_well_to_load_cell(handles);
            else
                disp('at loadcell');
end

finalConfig = cell(10,3);
for i=1:10
    finalConfig(i,1) = cellstr(strcat('Well ',num2str(i)));     % Well
    finalConfig(i,2) = cellstr(handles.curwell(i).color);       % Color
    finalConfig(i,3) = cellstr(num2str(handles.curwell(i).layers));      % Layer
end

% update final configuration table
set(handles.table_FinalConfiguration,'Data',finalConfig);
set(handles.table_FinalConfiguration,'ColumnName',{'Location';'Color';'Layers'});

handles.armposition = 0;
x = 0;
set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
stop_toc = toc(start_tic);
set(handles.text_SolveTimeValue,'String',stop_toc);
red_off(handles);
green_on(handles);



guidata(hObject, handles);
%uiresume();



% --- Executes on selection change in pum_Well10Layer.
function pum_Well10Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(10,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well10Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well10Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well10Color.
function pum_Well10Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(10,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well10Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well10Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well9Layer.
function pum_Well9Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(9,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well9Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well9Color.
function pum_Well9Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(9,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well9Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well8Layer.
function pum_Well8Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(8,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well8Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well8Color.
function pum_Well8Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(8,wcolor,handles.finalwell);
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function pum_Well8Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well7Layer.
function pum_Well7Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(7,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well7Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well7Color.
function pum_Well7Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(7,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well7Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well6Layer.
function pum_Well6Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(6,wlayer,handles.finalwell);
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function pum_Well6Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well6Color.
function pum_Well6Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(6,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well6Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well5Layer.
function pum_Well5Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(5,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well5Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well5Color.
function pum_Well5Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(5,wcolor,handles.finalwell);
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function pum_Well5Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well4Layer.
function pum_Well4Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(4,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well4Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well4Color.
function pum_Well4Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(4,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well4Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well3Layer.
function pum_Well3Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(3,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well3Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well3Color.
function pum_Well3Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(3,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well3Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well2Layer.
function pum_Well2Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(2,wlayer,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well2Layer_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well2Color.
function pum_Well2Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(2,wcolor,handles.finalwell);
guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function pum_Well2Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well1Color.
function pum_Well1Color_Callback(hObject, eventdata, handles)
wc = cellstr(get(hObject, 'String'));
wcolor = wc{get(hObject, 'Value')};
handles.finalwell = wColorIns(1,wcolor,handles.finalwell);
guidata(hObject,handles);
%disp('xd');

% --- Executes during object creation, after setting all properties.
function pum_Well1Color_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well1Layer.
function pum_Well1Layer_Callback(hObject, eventdata, handles)
wl = cellstr(get(hObject, 'String'));
wlayer = wl{get(hObject, 'Value')};
handles.finalwell = wLayerIns(1,wlayer,handles.finalwell);
guidata(hObject,handles);
%disp(handles.finalwell(1));

% --- Executes during object creation, after setting all properties.
function pum_Well1Layer_CreateFcn(hObject, eventdata, handle)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in pb_ReadForeground.
function pb_ReadForeground_Callback(hObject, eventdata, handles)
% hObject    handle to pb_ReadForeground (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%init
initConfig = cell(10,2); 
pumColor = cell(get(handles.pum_Well1Color,'String'));
for i=1:10
    initConfig(i,1) = cellstr(strcat('Well ',num2str(i)));     
    initConfig(i,2) = cellstr('None'); 
end
handles.imagewell = wInit();
%handles.finalwell = wInit();
handles.img = snapshot(handles.cam);
handles.img = imrotate(handles.img,180);
imwrite(handles.img,'foreground.png');
imshow(handles.img);
[handles.components, handles.dilate] = image_processing(handles.gb, handles.img);
[handles.stats, handles.radii] = color_processing(handles.components);
guidata(hObject, handles);
[handles.gameState, handles] = color(handles, hObject, handles.img, handles.dilate, handles.stats, handles.radii, handles.well_pixels);
% guidata(hObject, handles);
%update initial configuration table 

pumColor = cell(get(handles.pum_Well1Color,'String'));
for i = 1:10     
    initConfig(i,1) = cellstr(strcat('Well ',num2str(i)));     
    initConfig(i,2) = cellstr(handles.imagewell(i).color); 
end
% ---- Delete this segment if code above works correctly % initConfig(1,2) = cellstr(pumColor{get(handles.pum_Well1Color,'Value')}); % initConfig(2,2) = cellstr(pumColor{get(handles.pum_Well2Color,'Value')}); % initConfig(3,2) = cellstr(pumColor{get(handles.pum_Well3Color,'Value')}); % initConfig(4,2) = cellstr(pumColor{get(handles.pum_Well4Color,'Value')}); % initConfig(5,2) = cellstr(pumColor{get(handles.pum_Well5Color,'Value')}); % initConfig(6,2) = cellstr(pumColor{get(handles.pum_Well6Color,'Value')}); % initConfig(7,2) = cellstr(pumColor{get(handles.pum_Well7Color,'Value')}); % initConfig(8,2) = cellstr(pumColor{get(handles.pum_Well8Color,'Value')}); % initConfig(9,2) = cellstr(pumColor{get(handles.pum_Well9Color,'Value')}); % initConfig(10,2) = cellstr(pumColor{get(handles.pum_Well10Color,'Value')}); % for i = 1:10 %    if strcmp(initConfig(i,2),'None') %        initConfig(i,2) = cellstr('n/a'); %    end % end % ---- Delete code above if preceding code works correctly  % write initial configuration to table_InitialConfiguration 
set(handles.table_InitialConfiguration,'Data',initConfig);
set(handles.table_InitialConfiguration,'ColumnName',{'Location';'Color'})
guidata(hObject, handles);

function well = wInit()
    for i = 1:10
        well(i).correct = 0;
        well(i).empty = 1;
        well(i).color = 'None';
        well(i).layers = 0;
    end
    
function struct = wLayerIns(num,layer,struct)
    %layer = str2num(layer);
    disp(layer);
    if strcmp(layer,'--Select Layers--') == 1
        layer = '0';
    end
    struct(num).layers = layer;
    
    if layer == 0
        struct(num).empty = 1;
    elseif (struct(num).empty == 1)
        struct(num).empty = 0;
    end
    
function struct = wColorIns(num,colorin,struct)
    
    if strcmp(colorin,'Blue') == 0 && strcmp(colorin,'Red') == 0 && strcmp(colorin,'Green') == 0
        colorin = 'None';
    end
    struct(num).color = colorin;
    if strcmp(colorin,'None') == 1
        struct(num).empty = 1;
    elseif (struct(num).empty == 1)
        struct(num).empty = 0;
    end
    
function [components, dilate] = image_processing(gb, img)
    histgb = rgb2gray(gb);
    histimg = rgb2gray(img);
    foreground = imsubtract(histgb, histimg);

    level = 0.1; % 0.04 and 0.02 acceptable
    thresh = im2bw(foreground, level);

    se_setting_0 = 4;
    se_erode = strel('disk', se_setting_0);
    erode = imerode(thresh, se_erode);
    postfill = imfill(erode, 'holes');

    se_setting_1 = 4;
    se_dilate = strel('disk', se_setting_1);
    dilate = imdilate(postfill, se_dilate);
    imshowpair(img, dilate, 'montage');
    components = bwconncomp(dilate);

    function [stats, radii] = color_processing(components)
        stats = regionprops('table',components,'Centroid', ...
                             'MajorAxisLength','MinorAxisLength','BoundingBox', 'Area');
          % Get centers and radii of the circles
          centers = stats.Centroid;
          diameters = mean([stats.MajorAxisLength stats.MinorAxisLength],2);
          radii = diameters/2;

function [gameState, handles] = color(handles, hObject, img,dilate,stats,radii,well_pixels)

    gameState.Loc=[0,0,0,0,0,0,0,0,0,0];
    gameState.wellColor = [0,0,0,0,0,0,0,0,0,0]; % color of the stickers in the desired locations
    gameState.key={'0', 'Empty';'1', 'Red'; '2', 'Green'; '3', 'Yellow'; '4', 'Blue'}; %key
    gameState.used = [0,0,0,0,0,0,0,0,0,0];
    %%c define the angle arrays
    gameState.currentAngle = 0;
    gameState.stats = stats;
    gameState.dilate = dilate;
    gameState.radii = radii;
    gameState.testing_img = img;
    
        maskedRGBImage = img;

        % Set background pixels where BW is false to zero.
        maskedRGBImage(repmat(~dilate,[1 1 3])) = 0;
%        imshow(maskedRGBImage)
        %HSL and HSV are both cylindrical geometries (fig. 2), with hue, their angular dimension, starting at the red primary at 0�, passing through the green primary at 120� and the blue primary at 240�, and then wrapping back to red at 360�. In each geometry, the central vertical axis comprises the neutral, achromatic, or gray colors, ranging from black at lightness 0 or value 0, the bottom, to white at lightness 1 or value 1, the top.
         %red
         channelHueMin = 0;
         channelHueMax = 1;

         % % Define thresholds for 'Saturation'
         channelSaturationMin = 0.2;%%255;
         channelSaturationMax = 1;%0;

         % Define thresholds for 'Value'
         channelValueMin = 0;%255;
         channelValueMax = 0.7;%0;

        I = rgb2hsv(img);
        % Create mask based on chosen histogram thresholds
        BW = ((I(:,:,1) >= channelHueMin) | (I(:,:,1) <= channelHueMax) ) & ...
            (I(:,:,2) >= channelSaturationMin ) & (I(:,:,2) <= channelSaturationMax) & ...
            (I(:,:,3) >= channelValueMin ) & (I(:,:,3) <= channelValueMax);

        % Set background pixels where BW is false to zero.
        maskedRGBImage(repmat(~BW,[1 1 3])) = 0;
        dstats = regionprops('table',dilate,'Centroid', ...
                                 'MajorAxisLength','MinorAxisLength','BoundingBox', 'Area');
        imshow(maskedRGBImage)        
        hold on
        diameters = mean([stats.MajorAxisLength stats.MinorAxisLength],2);
              radii = diameters/2;      
    x = -1;
          hold on   
          gameState.numel = numel(stats.Area);
    
          
    j = 1;
    handles.totalwashers = 0;
    for i = 1:10 %for all wells
        for k = 1:numel(stats.Area)
        if check_spot(i,well_pixels(i,:), stats.Centroid(k,:)) == 1
            handles.totalwashers = handles.totalwashers + 1;
            retcolor = color_detection(maskedRGBImage,stats,radii,k);
            handles.imagewell(i).color = retcolor;
            handles.imagewell(i).empty = 0;
            disp(i);
            j = j + 1;
                break;
        end
        end
    end

            
         disp(gameState)

           if x ~= -1
               
            text(stats.Centroid(i,1), stats.Centroid(i,2), sprintf('%d', i), ...
        'HorizontalAlignment', 'center', ...
        'VerticalAlignment', 'middle');
%             set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
           end
           hold off
            pause(.05) % for speed 0.05  
 guidata(hObject, handles);

    
    function bool = check_spot(i, pixels, spot);
        if spot(1) > pixels(1) && spot(1) < pixels(2) && spot(2) > pixels(3) && spot(2) < pixels(4)
            bool = 1;
        else
            bool = 0;
        end





% --- Executes on button press in pb_Reset.
function pb_Reset_Callback(hObject, eventdata, handles)
% hObject    handle to pb_Reset (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles = resetGUI(handles);
guidata(hObject, handles);

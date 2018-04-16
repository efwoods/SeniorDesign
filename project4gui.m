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

% Last Modified by GUIDE v2.5 15-Apr-2018 13:24:47

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
handles.simulation_name = 'dc_motor_encoder_hardware_simulated';
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
                430 480 250 300; 460 520 240 290; 360 420 100 150; 300 350 38 88; 230 280 110 160;
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
setup_arduino(hObject, handles)
% UIWAIT makes project4gui wait for user response (see UIRESUME)
uiwait(handles.figure1);

% Force configuration tables to display 10 rows
initialConfigCol = 2;
initialConfigRow = 10;
finalConfigCol = 3;
finalConfigRow = 10;
set(handles.table_InitialConfiguration,'Data',cell(initialConfigRow,initialConfigCol))
set(handles.table_FinalConfiguration,'Data',cell(finalConfigRow,finalConfigCol))
ti = handles.table_InitialConfiguration;
tf = handles.table_FinalConfiguration;
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
imshow(handles.gb);
guidata(hObject, handles);


% --- Executes on button press in pb_Start.
function pb_Start_Callback(hObject, eventdata, handles)
% hObject    handle to pb_Start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('starting');
% testing case only
disp('testing')
rotate_from_load_cell_to_outer_well(handles)
handles.checkedwashers = handles.totalwashers;
for i = 1:10
     if (handles.curwell(i).empty == 0)
         x = handles.wellLocations(i).cw;
%           load(handles.tg, handles.simulation_name)
         set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
         if mod(i,2)==0
%              rotate_from_INNER_well_to_OUTER_well(hw)
             pick_up_washer(handles)
             rotate_from_outer_well_to_load_cell(handles)
             pause(.3)
             emag_off
             pause(.3)
             pick_up_washer(handles)
             rotate_from_load_cell_to_outer_well(handles)
             pause(.3)
             emag_off
             pause(.3)
             rotate_from_OUTER_well_to_INNER_well(handles) % temporary
             handles.checkedwashers = handles.checkedwashers - 1;
             if (handles.checkedwashers == 0)
                 rotate_from_outer_well_to_load_cell(handles)
             end
          else
%              rotate_from_loadcell_to_innerwell(handles)
%              rotate_from_OUTER_well_to_INNER_well(hw)
             pick_up_washer(handles)
             rotate_to_loadcell(handles)
             pause(.3)
             emag_off
             pause(.3)
             pick_up_washer(handles)
             rotate_from_loadcell_to_innerwell(handles)
             pause(.3)
             emag_off
             pause(.3)
             rotate_from_INNER_well_to_OUTER_well(handles) % temporary
             handles.checkedwashers = handles.checkedwashers - 1;
             if handles.checkedwashers == 0
                 rotate_to_loadcell(handles)
             end
          end
     end
end
x = 0;
set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
      

uiresume();



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
handles.img = snapshot(handles.cam);
handles.img = imrotate(handles.img,180);
imshow(handles.img);
[handles.components, handles.dilate] = image_processing(handles.gb, handles.img);
[handles.stats, handles.radii] = color_processing(handles.components);
guidata(hObject, handles);
[handles.gameState, handles] = color(handles, hObject, handles.img, handles.dilate, handles.stats, handles.radii, handles.well_pixels);
% guidata(hObject, handles);
%update initial configuration table 
initConfig = cell(10,2); 
pumColor = cell(get(handles.pum_Well1Color,'String'));
for i = 1:10     
    initConfig(i,1) = cellstr(strcat('Well ',num2str(i)));     
    initConfig(i,2) = cellstr(handles.curwell(i).color); 
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
    struct(num).layers = layer;
    if struct(num).empty == 1;
        struct(num).empty = 0;
    end
    
function struct = wColorIns(num,colorin,struct)
    struct(num).color = colorin;
    if struct(num).empty == 1;
        struct(num).empty = 0;
    end
    
function [components, dilate] = image_processing(gb, img)
    histgb = rgb2gray(gb);
    histimg = rgb2gray(img);
    foreground = imsubtract(histgb, histimg);

    level = 0.02;
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
        %HSL and HSV are both cylindrical geometries (fig. 2), with hue, their angular dimension, starting at the red primary at 0°, passing through the green primary at 120° and the blue primary at 240°, and then wrapping back to red at 360°. In each geometry, the central vertical axis comprises the neutral, achromatic, or gray colors, ranging from black at lightness 0 or value 0, the bottom, to white at lightness 1 or value 1, the top.
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
        if check_spot(i,well_pixels(i,:), stats.Centroid(j,:)) == 1
            handles.totalwashers = handles.totalwashers + 1;
            retcolor = color_detection(maskedRGBImage,stats,radii,j);
            handles.curwell(i).color = retcolor;
            handles.curwell(i).empty = 0;
            disp(i);
            j = j + 1;
            if j > numel(stats.Area) %escape
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




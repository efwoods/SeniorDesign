function varargout = project3gui(varargin)
% PROJECT3GUI MATLAB code for project3gui.fig
%      PROJECT3GUI, by itself, creates a new PROJECT3GUI or raises the existing
%      singleton*.
%
%      H = PROJECT3GUI returns the handle to a new PROJECT3GUI or the handle to
%      the existing singleton*.
%
%      PROJECT3GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROJECT3GUI.M with the given input arguments.
%
%      PROJECT3GUI('Property','Value',...) creates a new PROJECT3GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before project3gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to project3gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help project3gui

% Last Modified by GUIDE v2.5 07-Mar-2018 11:26:33

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @project3gui_OpeningFcn, ...
                   'gui_OutputFcn',  @project3gui_OutputFcn, ...
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

% --- Executes just before project3gui is made visible.
function project3gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to project3gui (see VARARGIN)

handles.cam = webcam('HP USB Webcam');
defaultImage = snapshot(handles.cam);                                        % read in image
set(handles.axes_image, 'Units', 'pixels', 'Position', [10, 10, 640, 480]);     % set size of axes in gui
resizePos = get(handles.axes_image,'Position');                                 % retrieve size of axes in gui
defaultImage = imresize(defaultImage, [resizePos(3) resizePos(3)]);             % resize image to fit gui axes
axes(handles.axes_image);                                                       % activate gui axes
imshow(defaultImage);                                                           % show image on gui axes

% ---------------------------------------------------------
% ----- resizes image to fit given gui axes -----
%myImage = imread('as.jpg');
%set(handles.axes7,'Units','pixels');
%resizePos = get(handles.axes_image,'Position');
%myImage= imresize(myImage, [resizePos(3) resizePos(3)]);
%axes(handles.axes_image);
%imshow(myImage);
%set(handles.axes_image,'Units','normalized');

% ----- how to link to simulink? -----
% open_system('MySimulation.mdl') %load_system('MySimulation.mdl')
% set_param('MySimulation.mdl', 'SimulationCommand', 'start')
% ---------------------------------------------------------

% Choose default command line output for project3gui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes project3gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% --- Outputs from this function are returned to the command line.
function varargout = project3gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in pb_background.
function pb_background_Callback(hObject, eventdata, handles)
% hObject    handle to pb_background (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.gb = snapshot(handles.cam);
backgroundImage = handles.gb;
resizePos = get(handles.axes_image,'Position');
backgroundImage = imresize(backgroundImage, [resizePos(3) resizePos(3)]);
axes(handles.axes_image);
imwrite(handles.gb,'backgroundImage.png')
imshow(backgroundImage);
guidata(hObject, handles);

% --- Executes on button press in pb_red.
function pb_red_Callback(hObject, eventdata, handles)
% hObject    handle to pb_red (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% % handles    structure with handles and user data (see GUIDATA)
    disp('point_to_colors')   
    point_to_color(1,handles.gameState) % Red
    x = 0;
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
% redImage = imread('test_red.png');
% set(handles.axes_image,'Units','pixels');
% resizePos = get(handles.axes_image,'Position');
% redImage = imresize(redImage, [resizePos(3) resizePos(3)]);
% axes(handles.axes_image);
imshow(handles.img);

guidata(hObject, handles);

% --- Executes on button press in pb_foreground.
function pb_foreground_Callback(hObject, eventdata, handles)
% hObject    handle to pb_foreground (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%% new
handles.img = capture_foreground(handles.cam);
handles.gb = imread('backgroundImage.png');
handles.gameState.wellColor = [0,0,0,0,0,0,0,0,0,0];
handles.gameState.Loc = [0,0,0,0,0,0,0,0,0,0];
[handles.components,handles.dilate] = image_processing(handles.gb, handles.img);
    [handles.stats, handles.radii] = color_processing(handles.components);
    handles.gameState = color(handles.img,handles.dilate,handles.stats, handles.radii);
    handles.gameState.zero = [310, 422];
    handles.gameState.center = [311, 251];
guidata(hObject, handles);
% disp('here')
%     %% update img
%  foregroundImage = imread(handles.img);
%  resizePos = get(handles.axes_image,'Position');
%  foregroundImage = imresize(foregroundImage, [resizePos(3) resizePos(3)]);
%  axes(handles.axes_image);
%  imshow(foregroundImage);

x = 0;
set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
imshow(handles.img);
guidata(hObject, handles);

% --- Executes on button press in pb_green.
function pb_green_Callback(hObject, eventdata, handles)
% hObject    handle to pb_green (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    disp('point_to_colors')    
    point_to_color(2,handles.gameState) % Green
    x = 0;
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
% greenImage = imread('test_green.png');
% resizePos = get(handles.axes_image,'Position');
% greenImage = imresize(greenImage, [resizePos(3) resizePos(3)]);
% axes(handles.axes_image);
% imshow(greenImage);
guidata(hObject, handles);

% --- Executes on button press in pb_cycle.
function pb_cycle_Callback(hObject, eventdata, handles)
% hObject    handle to pb_cycle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('point_to_colors')   
    point_to_color(1,handles.gameState) % Red
%     
% redImage = imread('test_red.png');
% set(handles.axes_image,'Units','pixels');
% resizePos = get(handles.axes_image,'Position');
% redImage = imresize(redImage, [resizePos(3) resizePos(3)]);
% axes(handles.axes_image);
% imshow(redImage);


%%pb_red_Callback(handles.pb_red , eventdata, handles);
pause(0.5);

disp('point_to_colors')    
    point_to_color(2,handles.gameState) % Green
%     x = 0;
%     set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
% greenImage = imread('test_green.png');
% resizePos = get(handles.axes_image,'Position');
% greenImage = imresize(greenImage, [resizePos(3) resizePos(3)]);
% axes(handles.axes_image);
% imshow(greenImage);

% pb_green_Callback(handles.pb_green, eventdata, handles);
pause(0.5);

disp('point_to_colors')
    point_to_color(4,handles.gameState) % Blue
% blueImage = imread('test_blue.png');
% resizePos = get(handles.axes_image,'Position');
% blueImage = imresize(blueImage, [resizePos(3) resizePos(3)]);
% axes(handles.axes_image);
% imshow(blueImage);
pause(0.5);
x = 0;
set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));

% below is same code as OpenFn, not sure how to run OpenFn again
% defaultImage = imread('test_white.png');                                        % read in image
% set(handles.axes_image, 'Units', 'pixels', 'Position', [10, 10, 640, 480]);     % set size of axes in gui
% resizePos = get(handles.axes_image,'Position');                                 % retrieve size of axes in gui
% defaultImage = imresize(defaultImage, [resizePos(3) resizePos(3)]);             % resize image to fit gui axes
% axes(handles.axes_image);                                                       % activate gui axes
% imshow(defaultImage);     
% show image on gui axes

% --- Executes on button press in pb_blue.
function pb_blue_Callback(hObject, eventdata, handles)
% hObject    handle to pb_blue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    disp('point_to_colors')
    point_to_color(4,handles.gameState) % Blue
% blueImage = imread('test_blue.png');
% resizePos = get(handles.axes_image,'Position');
% blueImage = imresize(blueImage, [resizePos(3) resizePos(3)]);
% axes(handles.axes_image);
% imshow(blueImage);
x = 0;
set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function axes_image_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes_image (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes_image


% --- Executes on selection change in pum_position.
function pum_position_Callback(hObject, eventdata, handles)
% hObject    handle to pum_position (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
 
% Hints: contents = cellstr(get(hObject,'String')) returns pum_position contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_position
contents = cellstr(get(hObject,'String'));
selection = contents(get(hObject,'Value'));

if strcmp(selection,'Position 1') == 1
    x = handles.gameState.Loc(1);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos1\n');
elseif strcmp(selection,'Position 2') == 1
    x = handles.gameState.Loc(2);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos2\n');
elseif strcmp(selection,'Position 3') == 1
    x = handles.gameState.Loc(3);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos3\n');
elseif strcmp(selection,'Position 4') == 1
    x = handles.gameState.Loc(4);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos4\n');
elseif strcmp(selection,'Position 5') == 1
    x = handles.gameState.Loc(5);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos5\n');
elseif strcmp(selection,'Position 6') == 1
    x = handles.gameState.Loc(6);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos6\n');
elseif strcmp(selection,'Position 7') == 1
    x = handles.gameState.Loc(7);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos7\n');
elseif strcmp(selection,'Position 8') == 1
    x = handles.gameState.Loc(8);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos8\n');
elseif strcmp(selection,'Position 9') == 1
    x = handles.gameState.Loc(9);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos9\n');
elseif strcmp(selection,'Position 10') == 1
    x = handles.gameState.Loc(10);
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
    fprintf('pos10\n');
elseif strcmp(selection,'Reference Position') == 1
    fprintf('Start\n');
end
pause(1)
x = 0;
    set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));




% --- Executes during object creation, after setting all properties.
function pum_position_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_position (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function [gb,cam,call] = first_call
cam = initialize_cam;
% gb = background(cam);
% restart
% cam = initialize_cam;
gb = background(cam);

function gb = restart
clc;
close all;
gb = init_gb;

function cam = initialize_cam
%% initialize cam
 cam = webcam('HP USB Webcam');

function gb = background(cam)
preview(cam)
pause(1)
closePreview(cam)
gb = snapshot(cam);
imwrite(gb,'newest_gb.png');

function img = capture_foreground(cam)
img = snapshot(cam);

function gb = init_gb
gb = imread('newest_gb.png');

function [components,dilate] = image_processing(gb, img)
histimg = rgb2gray(gb);
newimg2 = rgb2gray(img);
foreground= imsubtract(histimg, newimg2); %subtracts the background
% figure, imshow (foreground); %Foreground pixels separated 

level = 0.04; %0.04@ 12:49 %0.19 @ 11:31 am
thresh = im2bw(foreground, level); % thresh has a value of 1 for all values with luminance greater than level
% postfill = imfill(thresh, 'holes')

se_setting0 = 4; %4 @ 11:31 am cloudy %4 @ 4:25

se_erode = strel('disk',se_setting0); % Structural element of 5x5 
erode = imerode(thresh, se_erode);
postfill = imfill(erode,'holes');
% imshow(erode)

se_setting1 = 4; %11:31 am
se_dilate = strel('disk',se_setting1);
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
         
function [gameState] = color(img,dilate,stats,radii)

    gameState.Loc=[0,0,0,0,0,0,0,0,0,0];
    gameState.wellColor = [0,0,0,0,0,0,0,0,0,0]; % color of the stickers in the desired locations
    gameState.key={'0', 'Empty';'1', 'Red'; '2', 'Green'; '3', 'Yellow'; '4', 'Blue'}; %key
    gameState.used = [0,0,0,0,0,0,0,0,0,0];
    %%c define the angle arrays
    gameState.sortedRedAngle = [0,0,0,0,0,0,0,0,0,0];
    gameState.sortedBlueAngle = [0,0,0,0,0,0,0,0,0,0];
    gameState.sortedGreenAngle = [0,0,0,0,0,0,0,0,0,0];
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
        % % plot the original image, mask and filtered image all in one figure
        % subplot(1,3,1);imshow(img);title('Original Image');
        % subplot(1,3,2);imshow(BW);title('Mask');
        % subplot(1,3,3);imshow(maskedRGBImage);title('Filtered Image');
    x = -1;
          hold on   
          gameState.numel = numel(stats.Area);
          
    for i = 1:numel(stats.Area)
        disp(gameState)
            if ((~gameState.used(10)) && stats.Centroid(i,1) < 263) && (stats.Centroid(i,1) > 205) && (stats.Centroid(i,2) > 372) && (stats.Centroid(i,2) < 428) % measuring the x coordinate
                disp('location 10')
                gameState.wellColor(10) = color_detection(maskedRGBImage,stats,radii,i);
                x = 337.5; %-22.5
                gameState.Loc(10) = x;
                gameState.used(10) = 1;
            elseif ((~gameState.used(9)) && stats.Centroid(i,1) < 226) && (stats.Centroid(i,1) > 165) && (stats.Centroid(i,2) > 284) && (stats.Centroid(i,2) < 342) % measuring the x coordinate
                disp('location 9')
                gameState.wellColor(9) = color_detection(maskedRGBImage,stats,radii,i);
                x = 306;
                gameState.Loc(9) = x;
                gameState.used(9) = 1;
            elseif ((~gameState.used(8)) && stats.Centroid(i,1) < 177) && (stats.Centroid(i,1) > 100) && (stats.Centroid(i,2) > 215) && (stats.Centroid(i,2) < 282) % measuring the x coordinate
                disp('location 8')
                gameState.wellColor(8) = color_detection(maskedRGBImage,stats,radii,i);
                x = 270;
                gameState.Loc(8) = x;
                gameState.used(8) = 1;
            elseif ((~gameState.used(7)) && stats.Centroid(i,1) < 242) && (stats.Centroid(i,1) > 171) && (stats.Centroid(i,2) > 156) && (stats.Centroid(i,2) < 215) % measuring the x coordinate
                disp('location 7')
                gameState.wellColor(7) = color_detection(maskedRGBImage,stats,radii,i);
                x = 234;
                gameState.Loc(7) = x;
                gameState.used(7) = 1;
            elseif ((~gameState.used(6)) && stats.Centroid(i,1) < 270) && (stats.Centroid(i,1) > 208) && (stats.Centroid(i,2) > 64) && (stats.Centroid(i,2) < 125) % measuring the x coordinate
                disp('location 6')
                gameState.wellColor(6) = color_detection(maskedRGBImage,stats,radii,i);
                x = 202.5;
                gameState.Loc(6) = x;
                gameState.used(6) = 1;
            elseif ((~gameState.used(5)) && stats.Centroid(i,1) < 375) && (stats.Centroid(i,1) > 303) && (stats.Centroid(i,2) > 91) && (stats.Centroid(i,2) < 157) % measuring the x coordinate
                disp('location 5') %%
                gameState.wellColor(5) = color_detection(maskedRGBImage,stats,radii,i);
                x = 162;
                gameState.Loc(5) = x;
                gameState.used(5) = 1;
            elseif ((~gameState.used(4)) && stats.Centroid(i,1) < 476) && (stats.Centroid(i,1) > 397) && (stats.Centroid(i,2) > 95) && (stats.Centroid(i,2) < 174) % measuring the x coordinate
                disp('location 4')
                gameState.wellColor(4) = color_detection(maskedRGBImage,stats,radii,i);
                x = 135;
                gameState.Loc(4) = x;
                gameState.used(4) = 1;
            elseif ((~gameState.used(3)) && stats.Centroid(i,1) < 468) && (stats.Centroid(i,1) > 397) && (stats.Centroid(i,2) > 227) && (stats.Centroid(i,2) < 285) % measuring the x coordinate
                disp('location 3')
                gameState.wellColor(3) = color_detection(maskedRGBImage,stats,radii,i);
                x = 90;
                gameState.Loc(3) = x;
                gameState.used(3) = 1;
            elseif ((~gameState.used(2)) && stats.Centroid(i,1) < 462) && (stats.Centroid(i,1) > 394) && (stats.Centroid(i,2) > 346) && (stats.Centroid(i,2) < 407) % measuring the x coordinate
                disp('location 2')
                gameState.wellColor(2) = color_detection(maskedRGBImage,stats,radii,i);
                x = 45;
                gameState.Loc(2) = x;
                gameState.used(2) = 1;
            elseif ((~gameState.used(1)) && stats.Centroid(i,1) < 380) && (stats.Centroid(i,1) > 302) && (stats.Centroid(i,2) > 340) && (stats.Centroid(i,2) < 400) % measuring the x coordinate
                disp('location 1')
                gameState.wellColor(1) = color_detection(maskedRGBImage,stats,radii,i);
                x = 18;
                gameState.Loc(1) = x;
                gameState.used(1) = 1;
            else 
                disp('Location not found')
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
    end
%     
%               gameState.redcount = 1;
%               gameState.bluecount = 1;
%               gameState.greencount = 1;
%           for i = 1:numel(stats.Area)
%               if (gameState.wellColor(i) == 1) %red
%                   gameState.sortedRedAngle(gameState.redcount) = gameState.Loc(i);%angle arr is set to desired angle
%                   gameState.redcount = gameState.redcount + 1;
%               elseif (gameState.wellColor(i) == 2) %green
%                   gameState.sortedGreenAngle(gameState.greencount) = gameState.Loc(i);%angle arr is set to desired angle
%                   gameState.greencount = gameState.greencount + 1;
%               elseif (gameState.wellColor(i) == 4) %blue
%                   gameState.sortedBlueAngle(gameState.bluecount) = gameState.Loc(i);%angle arr is set to desired angle
%                   gameState.bluecount = gameState.bluecount + 1;
%               end
%           end
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

% Last Modified by GUIDE v2.5 07-Apr-2018 20:11:35

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
% Update handles structure
guidata(hObject, handles);
% UIWAIT makes project4gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% Force configuration tables to display 10 rows
initialConfigCol = 2;
initialConfigRow = 10;
finalConfigCol = 3;
finalConfigRow = 10;
set(handles.table_InitialConfiguration,'Data',cell(initialConfigRow,initialConfigCol))
set(handles.table_FinalConfiguration,'Data',cell(finalConfigRow,finalConfigCol))



% --- Outputs from this function are returned to the command line.
function varargout = project4gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on key release with focus on figure1 or any of its controls.
function figure1_WindowKeyReleaseFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.FIGURE)
%	Key: name of the key that was released, in lower case
%	Character: character interpretation of the key(s) that was released
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) released
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pb_ReadBoard.
function pb_ReadBoard_Callback(hObject, eventdata, handles)
% hObject    handle to pb_ReadBoard (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pb_Start.
function pb_Start_Callback(hObject, eventdata, handles)
% hObject    handle to pb_Start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in pum_Well10Layer.
function pum_Well10Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well10Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well10Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well10Layer


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
% hObject    handle to pum_Well10Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well10Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well10Color


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
% hObject    handle to pum_Well9Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well9Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well9Layer


% --- Executes during object creation, after setting all properties.
function pum_Well9Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well9Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well9Color.
function pum_Well9Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well9Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well9Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well9Color


% --- Executes during object creation, after setting all properties.
function pum_Well9Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well9Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well8Layer.
function pum_Well8Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well8Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well8Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well8Layer


% --- Executes during object creation, after setting all properties.
function pum_Well8Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well8Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well8Color.
function pum_Well8Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well8Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well8Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well8Color


% --- Executes during object creation, after setting all properties.
function pum_Well8Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well8Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well7Layer.
function pum_Well7Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well7Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well7Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well7Layer


% --- Executes during object creation, after setting all properties.
function pum_Well7Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well7Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well7Color.
function pum_Well7Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well7Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well7Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well7Color


% --- Executes during object creation, after setting all properties.
function pum_Well7Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well7Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well6Layer.
function pum_Well6Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well6Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well6Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well6Layer


% --- Executes during object creation, after setting all properties.
function pum_Well6Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well6Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well6Color.
function pum_Well6Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well6Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well6Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well6Color


% --- Executes during object creation, after setting all properties.
function pum_Well6Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well6Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well5Layer.
function pum_Well5Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well5Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well5Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well5Layer


% --- Executes during object creation, after setting all properties.
function pum_Well5Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well5Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well5Color.
function pum_Well5Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well5Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well5Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well5Color


% --- Executes during object creation, after setting all properties.
function pum_Well5Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well5Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well4Layer.
function pum_Well4Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well4Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well4Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well4Layer


% --- Executes during object creation, after setting all properties.
function pum_Well4Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well4Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well4Color.
function pum_Well4Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well4Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well4Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well4Color


% --- Executes during object creation, after setting all properties.
function pum_Well4Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well4Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well3Layer.
function pum_Well3Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well3Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well3Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well3Layer


% --- Executes during object creation, after setting all properties.
function pum_Well3Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well3Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well3Color.
function pum_Well3Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well3Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well3Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well3Color


% --- Executes during object creation, after setting all properties.
function pum_Well3Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well3Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well2Layer.
function pum_Well2Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well2Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well2Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well2Layer


% --- Executes during object creation, after setting all properties.
function pum_Well2Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well2Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well2Color.
function pum_Well2Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well2Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well2Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well2Color


% --- Executes during object creation, after setting all properties.
function pum_Well2Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well2Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well1Color.
function pum_Well1Color_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well1Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well1Color contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well1Color


% --- Executes during object creation, after setting all properties.
function pum_Well1Color_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well1Color (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in pum_Well1Layer.
function pum_Well1Layer_Callback(hObject, eventdata, handles)
% hObject    handle to pum_Well1Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pum_Well1Layer contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pum_Well1Layer


% --- Executes during object creation, after setting all properties.
function pum_Well1Layer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pum_Well1Layer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

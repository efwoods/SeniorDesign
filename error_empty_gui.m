function error = error_empty_gui(handles)
error = 1;
for i = 1:10
    if strcmp(handles.finalwell(i).color, 'None') == 0  && handles.finalwell(i).layers ~= 0
        error = 0;
        return;
    end
end
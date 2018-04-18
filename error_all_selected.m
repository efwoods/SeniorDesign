function error = error_all_selected(handles)
    error = 0;
    for i = 1:10
        if strcmp(handles.finalwell(i).color,'None') == 1 && str2num(handles.finalwell(i).layers) ~= 0
            error = 1;
            break
        elseif strcmp(handles.finalwell(i).color,'None') == 0 && str2num(handles.finalwell(i).layers) == 0
            error = 1;
            break;
        end
    end
    
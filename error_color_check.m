function error = error_color_check(handles)
    rcount = 0;
    gcount = 0;
    bcount = 0;
    rcountf = 0;
    gcountf = 0;
    bcountf = 0;
    error = 0;
    for i = 1:10

        if strcmp(handles.imagewell(i).color, 'Red') == 1
            rcount = rcount + 1;
        elseif strcmp(handles.imagewell(i).color, 'Green') == 1
            gcount = gcount + 1;
        elseif strcmp(handles.imagewell(i).color, 'Blue') == 1
            bcount = bcount + 1;
        end
        
        if strcmp(handles.finalwell(i).color, 'Red') == 1
            rcountf = rcountf + 1;
        elseif strcmp(handles.finalwell(i).color, 'Green') == 1
            gcountf = gcountf + 1;
        elseif strcmp(handles.finalwell(i).color, 'Blue') == 1
            bcountf = bcountf + 1;
        end
        
    end
    
    if rcountf ~= rcount || gcountf ~= gcount || bcountf ~= bcount
           error = 1;
    end
        
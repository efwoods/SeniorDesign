function handles = well_verify_correct(num, handles)
    if handles.curwell(num).color == handles.finalwell(num).color && handles.curwell(num).layers == handles.finalwell(num).layers
        handles.curwell(num).correct = 1;
    else
        handles.curwell(num).correct = 0;
    end
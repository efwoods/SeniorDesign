%well_swap(handles.curwell(7), handles.loadcell)
function handles = well_swap(cur, dest)
    dest.color = cur.color;
    dest.layers = cur.layers;
    dest.empty = 0;
    cur.empty = 1;
    cur.color = 'None';
    cur.layers = 0;
    
    
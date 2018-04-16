function well = wInit()     
    for i = 1:10
        well(i).correct = 0;
        well(i).empty = 1;
        well(i).color = 'None';
        well(i).layers = 0;
    end
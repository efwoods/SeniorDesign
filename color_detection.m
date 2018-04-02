function RGB_COLOR = color_detection(maskedRGBImage, stats, radii, i)
[avR] = extract_colors(stats, radii, i, maskedRGBImage, 1); % key is 1 Red; 2 green; 3 blue
[avG] = extract_colors(stats, radii, i, maskedRGBImage, 2); % key is 1 Red; 2 green; 3 blue    
[avB] = extract_colors(stats, radii, i, maskedRGBImage, 3); % key is 1 Red; 2 green; 3 blue
    %     gameState.key={'0', 'Empty';'1', 'Red'; '2', 'Green'; '3', 'Yellow'; '4', 'Blue'} %key
 if avR > avG
     if avR > avB
         disp('Red')
         RGB_COLOR = 1;
     else
         disp('Blue')
         RGB_COLOR = 4;
     end
 elseif avG > avB
     disp('Green')
     RGB_COLOR = 2;
 else
     disp('Blue')
     RGB_COLOR = 4;
 end
end
function [mean_color] = extract_colors(stats, radii, i, maskedRGBImage, key) % key is 1 Red; 2 green; 3 blue
    rowCenter = (round(stats.Centroid(i,2)));
    rowCount = 0;
    delta = round(radii(i)/2);
    colCenter = (round(stats.Centroid(i,1)));
    colCount = 0;
    color_count = 0;
    entered = 0;
            imshow(maskedRGBImage), hold on % for testing
    for j = (rowCenter - delta) : (rowCenter + delta)        
        for k = (colCenter - delta) : (colCenter + delta)
            if(maskedRGBImage(j,k,key) ~= 0)
                entered = 1;
                color_count = color_count + 1;
%                  disp (color_count)
                color(color_count) = maskedRGBImage(j,k,key);
               plot(k, j, 'r.'); % for testing
              
%             else 
%                 disp (color_count)
%                 color(color_count) = 0;
            end
        end
    end
%     imshow(h)
    hold off
    if(entered)
        mean_color = round(mean(color));
    else
        mean_color = 0;
    end
%     imclose(h)
end
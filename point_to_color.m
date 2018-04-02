function point_to_color(color,gameState)

for i = 1:numel(gameState.wellColor)
    if color == gameState.wellColor(i)
        
        x = gameState.Loc(i);
        disp(x)
        set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
        
        if(gameState.wellColor(i) == 1)
            disp('Red')
        elseif (gameState.wellColor(i) == 2)
            disp('Green')
        elseif (gameState.wellColor(i) == 4)
            disp('Blue')
        end
        pause(1)
    end
end
        
pause(1)
% 
%  if color == 1
% %      for j = 1:(gameState.redcount)
% %              x = gameState.sortedRedAngle(j);
% %          set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
% %          disp('Red')
% %          pause(2)
% %      end
%  elseif color == 2
% %      for j = 1:(gameState.greencount)
% %          x = gameState.sortedGreenAngle(j);
% %          set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
% %          disp('Green')
% %          pause(2)
% %       end
%   elseif color == 4
%       
% %      for j = 1:(gameState.bluecount)
% %          x = gameState.sortedBlueAngle(j);
% %          set_param('dc_motor_encoder_hardware_simulated/Matlab_Input','Value', num2str(x));
% %          disp('Blue')
% %          pause(2)
% %      end
% else
%     disp('Error in point_to_color')
end
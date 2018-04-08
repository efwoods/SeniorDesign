function s = arduinoSetup()

    %MATLAB recognizes and initializes ARDUINOUNO
    a = arduino;

    %Sets ARDUINO pins and maximum and minimum traveling or Servo
    s = servo(a, 'D10', 'MaxPulseDuration', 2.55e-3, 'MinPulseDuration', 6.4e-4);

    %Moves arm to the back 
    writePosition(s, 1);
end
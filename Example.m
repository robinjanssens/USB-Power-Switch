% ==============================
%
% MATLAB example code for USB Power Switch
%
% Written by Robin Janssens (robin@robinjanssens.net)
%
% ==============================

s = serial('/dev/tty.usbserial-A5011FJZ');  % select serial port
set(s,'BaudRate',9600);                     % setup s with baud rate of 9600 baud/sec
fopen(s);                                   % open serial port

fprintf(s,'0');     % switch power off USB port
pause(2);           % wait for 2 seconds
fprintf(s,'1');     % switch power on USB port
pause(2);           % wait for 2 seconds
fprintf(s,'0');     % switch power off USB port
pause(2);           % wait for 2 seconds
fprintf(s,'1');     % switch power on USB port
pause(2);           % wait for 2 seconds
fprintf(s,'0');     % switch power off USB port

pause(2);           % wait for 2 seconds
fclose(s);      % close serial port
delete(s);      % delete serial port
clear s;        % remove s from workspace
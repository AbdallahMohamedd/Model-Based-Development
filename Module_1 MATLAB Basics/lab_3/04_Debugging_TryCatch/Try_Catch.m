%info
% This code is for debugging file reading in MATLAB
% This code is written in MATLAB
% This code is not run in C language

clc % Clear command window
clear % Clear workspace

try % Attempt to read a file
    fileID = fopen('nonexistent_file.txt', 'r'); % Open file for reading
    if (fileID == -1) % Check if file opened successfully 
        error('goto catch section'); % If not, throw an error
    end % End if
    fprintf('[Debug Message]: Read File Successfully!! \n'); 
catch % Catch any errors
    % This block executes if an error occurs in the try block
    fprintf('[Debug Message]: Unable to read File!! \n'); 
    fprintf('Check again');
end
%info
% This is a simple switch statement example in MATLAB
% The switch statement is used to execute one block of code among many
% based on the value of a variable.
% The switch statement is similar to the if-else statement, but it is
% more efficient and easier to read when there are many conditions to check.
% This code write to run in matlab only, not in C language
user_colour = input('Enter your favourite colour: ', 's'); % Prompt user for input
fprintf('You entered: %s\n', user_colour); % Debug line to check the input
switch user_colour          % Switch statement to check the value of user_colour
    case {'red', 'green'}   % Check if user_colour is 'red' or 'green'
        disp("You are select color in first list")
    case {'black', 'white'} % Check if user_colour is 'black' or 'white'
        disp("You are select color in second list")
    case {'blue', 'gray'}   % Check if user_colour is 'blue' or 'gray'
        disp("You are select color in third list")
    case {'rose', 'pink'}   % Check if user_colour is 'rose' or 'pink'
        disp("You are select color in fourth list")
    otherwise               % If user_colour does not match any case
        disp("You are select color in other list, please check your input");
end


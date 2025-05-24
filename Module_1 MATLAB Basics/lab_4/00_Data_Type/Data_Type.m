% info
% This script demonstrates the basic data types in MATLAB.
% It covers numeric arrays, cell arrays and structures.
% It also includes examples of using if statements, for loops, and plotting.
% This code is written in MATLAB
% This code is not run in C language

clc % Clear command window
clear % Clear workspace

% Create a cell array
cellArray = {1, 'Hello', [1, 2, 3], true}; % Cell array with mixed data types
disp('Cell Array:');
% Display the cell array
disp(cellArray);

% Create a structure
person.name = 'John Doe'; % Name field
person.age = 30; % Age field
person.isEmployed = true; % Employment status field
disp('Structure:');
% Display the structure
disp(person);

FirstName = 'Abdullah';
LastName = 'Mohammad';
FullName = horzcat(FirstName, ' ', LastName);
disp('FullName: ');
disp(FullName);

% If statement to checks if a number is even or odd
number = 5; % Example number
if (mod(number,2)==0)
    disp('Even Number');
else
    disp('Odd Number');
end

% For loop to iterate through a vector
vector = 1:10; % Example vector
disp('For Loop:');
for i = 1:length(vector)
    fprintf('%d ', vector(i));
end

y = 0:0.1:(2*pi); % Create a vector from 0 to 2*pi with a step of 0.1
plot(y, sin(y)) % Plot the sine function
xlabel('x') % Label x-axis
ylabel('sin(x)') % Label y-axis
title('Sine Function') % Title of the plot
grid on % Add grid to the plot


%info
% This code is for summation of numbers from 1 to N
% This code is written in MATLAB
% This code is not run in C language

clc   % Clear command window
clear % Clear all variables

N = input ("Enter the number to sum all numbers from 1 till this number");
sum = 0; % Initialize sum to 0
for index = 1 : N % Loop from 1 to N
    sum = sum + index; % Add index to sum
end 
% Print the result
fprintf("Summation of number from 1 to %d is %d\n", N, sum);
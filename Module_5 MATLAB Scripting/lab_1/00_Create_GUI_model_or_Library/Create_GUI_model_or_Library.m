%Information
% This script creates a new Simulink model or library based on user input.
% It prompts the user to choose between creating a model or a library and
% then asks for the name of the new system. Finally, it creates and opens
% the specified Simulink system.
clc;
clear;
close all;

disp('Choose the type of Simulink system to create:');                  % User prompt
disp('1. SIMULINK Model');                                              % User prompt
disp('2. SIMULINK Library');                                            % User prompt
choice = input('Enter 1 or 2: ');                                       % User input for choice
Name = input('Enter the name of the Model or Library: ', 's');          % User input for name
if choice == 1
    disp(['Simulink model named ', Name, ' created.']);                 % User feedback
    new_system(Name,"Model")                                            % Create new Simulink model
    open_system(Name)                                                   % Open the newly created model
elseif choice == 2
    disp(['Simulink library named ', Name, ' created.']);               % User feedback
    new_system(Name,"Library")                                          % Create new Simulink library
    open_system(Name)                                                   % Open the newly created library
else
    disp('Invalid choice.');                                            % Handle invalid input
end


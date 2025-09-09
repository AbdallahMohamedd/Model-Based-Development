%% Script Information
% Title: Simulink Block Creation and Configuration Demo
%
% Purpose:
%   Demonstrates automated creation and configuration of Simulink blocks
%   through MATLAB scripting
%
% Requirements:
%   - MATLAB R2024b or later
%   - Simulink package
%
% Features:
%   - Automated model creation
%   - Multiple block type demonstrations
%   - Different parameter setting methods
%   - Block handle management
%   - Hierarchical structure creation
%
% Block Types Demonstrated:
%   - Math Operations (Gain, Sum)
%   - Sources (Constants)
%   - Subsystems
%
% Author: Abdullah Mohamed Ibrahim
% Last Modified: September 9, 2025
% Version: 5.0

%% Environment Setup
% Clear workspace and command window
clc;                    % Clear command window
clear;                  % Clear workspace variables
close all;             % Close all figures

%% Model Initialization
% Create and open new Simulink model
modelName = 'Model_1';  % Define model name
new_system(modelName);  % Create new model
open_system(modelName); % Open model in Simulink

%% Mathematical Operations Block Creation
% Add Gain block
gainBlockPath = [modelName, '/01_GainBlock'];
add_block('simulink/Math Operations/Gain', gainBlockPath);

% Add Sum block
sumBlockPath = [modelName, '/01_SumBlock'];
add_block('simulink/Math Operations/Sum', sumBlockPath);

%% Constant Blocks Creation
% Method 1: Default constant (value = 1)
constBlock1Path = [modelName, '/01_ConstantBlock'];
BlockHandel_1 = add_block('simulink/Sources/Constant', constBlock1Path);

% Method 2: Direct value setting (value = 6)
constBlock2Path = [modelName, '/02_ConstantBlock'];
BlockHandel_2 = add_block('simulink/Sources/Constant', ...
    constBlock2Path, ...
    'value', '6');

% Method 3: Numeric conversion (value = 15)
constBlock3Path = [modelName, '/03_ConstantBlock'];
BlockHandel_3 = add_block('simulink/Sources/Constant', ...
    constBlock3Path, ...
    'value', num2str(15));

%% Subsystem Creation
% Add hierarchical subsystem block
subsysPath = [modelName, '/01_Subsystem'];
BlockHandel_4 = add_block('simulink/Commonly Used Blocks/Subsystem', ...
    subsysPath);

%% Block Handle Management
% Store handles in structure for future reference
handles.constant1 = BlockHandel_1;
handles.constant2 = BlockHandel_2;
handles.constant3 = BlockHandel_3;
handles.subsystem = BlockHandel_4;

% Note: Handles can be used for:
% - Block parameter modification
% - Connection creation
% - Position adjustment
% - Block deletion

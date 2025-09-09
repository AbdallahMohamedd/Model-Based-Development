%% Script Information
% Purpose: Demonstrates programmatic creation of Simulink blocks and subsystems
%
% Requirements:
% - MATLAB R2024b or later
% - Simulink package
%
% Features:
% - Creates a new Simulink model
% - Adds various blocks with different configurations
% - Demonstrates block handle usage
% - Shows different methods of setting block parameters
%
% Author: Abdullah Mohamed Ibrahim
% Last Modified: September 9, 2025
% Version: 5.0

%% Create and Open New Model
% Initialize a new Simulink model named 'Model_1'
new_system('Model_1');
open_system('Model_1');

%% Add Basic Math Operation Blocks
% Add a Gain block with default parameters
add_block('simulink/Math Operations/Gain','Model_1/01_GainBlock');

% Add a Sum block with default parameters
add_block('simulink/Math Operations/Sum','Model_1/01_SumBlock');

%% Add Constant Blocks with Different Configurations
% Method 1: Basic constant block with default value (1)
BlockHandel_1 = add_block('simulink/Sources/Constant', 'Model_1/01_ConstantBlock');

% Method 2: Constant block with direct numeric value (6)
BlockHandel_2 = add_block('simulink/Sources/Constant', ...
    'Model_1/02_ConstantBlock', ...
    'value', '6');

% Method 3: Constant block with converted numeric value (15)
BlockHandel_3 = add_block('simulink/Sources/Constant', ...
    'Model_1/03_ConstantBlock', ...
    'value', num2str(15));

%% Add Subsystem Block
% Create a subsystem block for hierarchical modeling
BlockHandel_4 = add_block('simulink/Commonly Used Blocks/Subsystem', ...
    'Model_1/01_Subsystem');

%% Note: Block handles are stored but not used in this version
% BlockHandel_1 through BlockHandel_4 can be used for further block
% modifications or connections in future enhancements

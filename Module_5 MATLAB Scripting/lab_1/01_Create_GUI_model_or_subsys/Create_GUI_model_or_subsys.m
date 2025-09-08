%% Script Information
% Purpose: Interactive tool for creating and managing Simulink models and subsystems
%
% Requirements:
% - MATLAB R2024b or later
% - Simulink package
%
% Features:
% - Creates new Simulink models dynamically
% - Adds subsystems to existing models
% - Maintains list of created models
% - Provides model existence verification
%
% Usage Instructions:
% 1. Run the script
% 2. Select operation type:
%    - Option 1: Create new Simulink model
%    - Option 2: Add subsystem to existing model
%    - Option 3: View all created models
% 3. Follow the prompts to enter required names
%
% Author: Abdullah Mohamed Ibrahim
% Last Modified: September 8, 2025
% Version: 3.0

%% Initialize Global Variables
ModelsNames = {};  % Cell array to store all created model names
i = 0;            % Counter for tracking number of created models

%% Main Program Loop
while(1)
    % Display menu separator and options
    disp('----------------------------------------------------------------------------------')
    disp('Choose the type of Simulink system to create:');
    disp('1. SIMULINK Model');
    disp('2. SIMULINK subsystem');
    disp('3. Display all created models')
    choice = input('Enter 1, 2 or 3: ');
    
    %% Option 1: Create New Simulink Model
    if choice == 1
        % Get model name from user
        ModelName = input('Enter the name of the Model: ', 's');
        
        % Update tracking variables
        i = i + 1;
        ModelsNames{i} = ModelName;  % Add new model to tracking array
        
        % Create and open the new model
        disp(['Simulink model named ', ModelName, ' created.']);
        new_system(ModelName,"Model")
        open_system(ModelName)
        
        %% Option 2: Add Subsystem to Existing Model
    elseif choice == 2
        % Get target model name from user
        WhichModel = input('Enter the name of the Model to add the Subsystem to: ', 's');
        FlagModelExist = false;
        
        % Verify model exists in tracking array
        for k = 1:length(ModelsNames)
            if strcmp(ModelsNames{k}, WhichModel)
                FlagModelExist = true;
                break;
            end
        end
        
        % Process based on model existence
        if FlagModelExist
            % Model exists - proceed with subsystem creation
            disp('Model exists!');
            SubsystemName = input('Enter the name of the Subsystem: ', 's');
            
            % Create and open the subsystem
            disp(['Simulink subsystem named ', SubsystemName, ' created.']);
            add_block('simulink/Ports & Subsystems/Subsystem', [WhichModel, '/', SubsystemName]);
            open_system([WhichModel, '/', SubsystemName])
        else
            % Model doesn't exist - display error
            disp('Model does NOT exist!');
            disp('Cannot create a subsystem in your chosen model!');
        end
        
        %% Option 3: Display All Created Models
    elseif choice == 3
        % Loop through and display all model names
        for d=1:length(ModelsNames)
            disp(ModelsNames{d})
        end
        
        % Handle empty list case
        if i == 0
            disp('Empty list')
        end
        
        %% Invalid Option Handler
    else
        disp('Invalid choice.');
    end
end

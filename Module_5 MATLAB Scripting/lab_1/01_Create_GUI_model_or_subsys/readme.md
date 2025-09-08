# Simulink Model & Subsystem Creator Tool

A MATLAB-based interactive tool for dynamically creating and managing Simulink models and subsystems.

## Requirements

- MATLAB R2024b or later
- Simulink package
- Windows operating system

## Features

- Dynamic creation of new Simulink models
- Addition of subsystems to existing models
- Model tracking and verification system
- Interactive command-line interface
- Model list display functionality

## Installation

1. Clone or download the repository
2. Navigate to `Module_5 MATLAB Scripting/lab_1/01_Create_GUI_model_or_subsys/`
3. Open MATLAB
4. Run Create_GUI_model_or_subsys.m

## Usage

### Starting the Tool
Run Create_GUI_model_or_subsys.m in MATLAB. The main menu will appear with three options:

1. Create SIMULINK Model
2. Add SIMULINK subsystem
3. Display all created models

### Creating a New Model
1. Select option `1`
2. Enter desired model name when prompted
3. Model will be created and opened automatically

### Adding a Subsystem
1. Select option `2`
2. Enter the name of an existing model
3. If model exists:
   - Enter desired subsystem name
   - Subsystem will be created and opened
4. If model doesn't exist:
   - Error message will be displayed
   - Return to main menu

### Viewing Created Models
1. Select option `3`
2. List of all created models will be displayed
3. "Empty list" message appears if no models exist

## File Structure

```
Module_5 MATLAB Scripting/
└── lab_1/
    └── 01_Create_GUI_model_or_subsys/
        ├── Create_GUI_model_or_subsys.m
        └── README.md
```

## Error Handling

- Invalid menu choices display error message
- Attempts to create subsystems in non-existent models are caught and reported
- Empty model list handling

## Version History

- Version 3.0 (Current)
  - Enhanced error handling
  - Improved model tracking
  - Added model list display feature

## Author

Abdullah Mohamed Ibrahim

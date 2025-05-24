% info
% Define the flag colors and dimensions
% This script draws the Palestinian flag using MATLAB.
% The flag consists of three horizontal stripes (black, white, and green)
% and a red triangle on the left side.
% The flag is drawn using rectangles and a filled polygon.
% The flag is displayed in a figure window.

GreenColor = [0, 0.51, 0.25];       % Green Color in RGB
WhiteColor = [1, 1, 1];             % White Color in RGB
BlackColor = [0, 0, 0];             % Black Color in RGB
RedColor = [0.698, 0.132, 0.203];   % Red Color in RGB

FlagWidth = 600; % Width of the flag in pixels
FlagHeight = 400; % Height of the flag in pixels

figure('Position', [200, 200, FlagWidth, FlagHeight]); % Create a figure window
rectangle('Position', [0, 0, FlagWidth, FlagHeight], 'FaceColor', GreenColor); % Draw the green rectangle
hold on; % Hold the current plot
rectangle('Position', [0, FlagHeight/3, FlagWidth, FlagHeight/3], 'FaceColor', WhiteColor);     % Draw the white rectangle
rectangle('Position', [0, 2*FlagHeight/3, FlagWidth, FlagHeight/3], 'FaceColor', BlackColor);   % Draw the black rectangle

triangleX = [0, FlagWidth/2, 0];            % X-coordinates of the triangle vertices
triangleY = [0, FlagHeight/2, FlagHeight];  % Y-coordinates of the triangle vertices

fill(triangleX, triangleY, RedColor); % Fill the triangle with red color
axis equal; % Set equal aspect ratio

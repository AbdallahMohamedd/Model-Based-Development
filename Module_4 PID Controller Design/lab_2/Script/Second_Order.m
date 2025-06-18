%info
% This script generates the step response of a second-order system with varying damping ratios (zeta).
% It uses the Control System Toolbox in MATLAB to create transfer functions and plot the step responses.

clc
clear
close all
% Define the damping ratios
for zeta = 0.25:0.25:1.5
    % Define the transfer function of the second-order system
    wn = 0.5;   % Natural frequency
    % Transfer function of the second-order system
    num = wn^2; % Numerator coefficients
    den = [1 2*zeta*wn wn^2]; % Denominator coefficients
    G = tf(num, den); % Transfer function
    hold on;
    step(G); % Step response of the system
    legend('zeta = 0.25', 'zeta = 0.5', 'zeta = 0.75', 'zeta = 1', 'zeta = 1.25');
    % Pole-zero map of the system
    title('step response of a second-order system with varying damping ratios (zeta) and constant natural frequencies.');
end

figure
% Define the Natural frequency
for wn = 0.75:0.5:2.75
    % Define the transfer function of the second-order system
    zeta = 0.5;   % Damping ratio
    % Transfer function of the second-order system
    num = wn^2; % Numerator coefficients
    den = [1 2*zeta*wn wn^2]; % Denominator coefficients
    G = tf(num, den); % Transfer function
    hold on;
    step(G); % Step response of the system
    legend('wn = 0.75', 'wn = 1.25', 'wn = 1.75', 'wn = 2.25', 'wn = 2.75');
    % Pole-zero map of the system
    title('step response of a second-order system with varying natural frequencies (wn) and constant zeta.');
end

clc

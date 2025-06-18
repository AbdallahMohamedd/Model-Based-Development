% info
% Draw the ramp signal response of a first-order system
% Ramp_Signal.m
% This script simulates the response of a first-order system to a ramp input signal.
% It defines the system parameters, creates the transfer function, and simulates the response using lsim.

k = 1;                  % Gain
R = 10e3;               % Resistance
C = 1e-7;               % Capacitance
T = R*C;                % Time constant
num = k;                % Numerator coefficients
den = [T 1] ;           % Denominator coefficients
G = tf(num, den)        % Transfer function
t = 0:0.1:10;           % Time vector for simulation
u_ramp = t;             % Ramp input signal
% Simulate the system response to the ramp input
[y_ramp t_ramp] = lsim(G,u_ramp,t);
plot(t_ramp, y_ramp) % Plot the system response
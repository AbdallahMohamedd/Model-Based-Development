% info
% First Order System Transfer Function
% This script defines a first-order transfer function using the transfer function (tf) command in MATLAB.
% It specifies the system parameters, including gain, resistance, and capacitance.
% The transfer function is then created using these parameters.

k = 1       ; % Gain
R = 10e3    ; % Resistance
C = 1e-7    ; % Capacitance
T = R*C     ; % Time constant
num = k     ; % Numerator coefficients
den = [T 1] ; % Denominator coefficients
G = tf(num, den)  % Transfer function
% G = tf([k],[T 1]); % Alternative way to define transfer function

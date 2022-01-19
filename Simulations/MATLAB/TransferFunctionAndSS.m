clear all;
close all;

% PARAMETERS
m = 0.11;   % mass of the ball [kg]      ADJUST TO REAL BALL MASS 
R = 0.015;   % radius of the ball [m]     ADJUST TO REAL BALL RADIUS
d = 0.03;   % lever arm offset [m]       ADJUST TO REAL LEVER ARM OFFSET
g = 9.8;    % gravitational acceleration
L = 1.0;    % length of the beam         ADJUST TO REAL BEAM LENGTH
J = 9.99e-6;    % ball's moment of inertia       ADJUST TO REAL VALUE
r = 0;      % ball position coordinate
alpha = 0;  % beam angle (radians)
theta = 0;  % servo angle (radians)

% TRANSFER FUNCTION
num = m*g*d; 
den = [L*((J/R^2) + m) 0 0]; 
Gs = tf(num, den) % [m/rad]

% STATE SPACE REPRESENTATION
H = -m*g/(J/(R^2)+m);
A = [0 1 0 0; 0 0 H 0; 0 0 0 1; 0 0 0 0]
B = [0 0 0 1]';
C = [1 0 0 0];
D = [0];
ball_ss = ss(A,B,C,D)






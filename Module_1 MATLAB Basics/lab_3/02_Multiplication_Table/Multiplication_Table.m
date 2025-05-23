%info
% This code for a multiplication table by nested for loop
% This code is written in MATLAB
% This code is not run in C language
fprintf("This code is for a multiplication table by nested for loop\n");
fprintf("table of 1 to 5\n");
fprintf("table 1:\n");
for i = 1:5
    for j = 1:5
        fprintf('%d x %d = %d\n', i, j, i*j); % Print the multiplication table
    end
    if i < 5
        fprintf("table %d:\n", i+1); % Print the table number
    end
end
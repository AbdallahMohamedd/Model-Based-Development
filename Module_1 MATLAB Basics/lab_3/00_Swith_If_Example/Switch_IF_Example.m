%%
% Switch case example in video number 30
value_switch = 2;
switch value_switch
    case 1
        disp('The value is 1');
    case 2
        disp('The value is 2');
    case 3
        disp('The value is 3');
    otherwise
        disp('The value is not 1, 2, or 3');
end

%%
value_if = 3;
if (value_if ==1)
    disp('The value is 1');
elseif (value_if == 2)
    disp('The value is 2');
elseif (value_if == 3)
    disp('The value is 3');
else
    disp('The value is not 1, 2, or 3');
end
% The switch case is more efficient than the if statement when there are many conditions to evaluate.
% This function plots the time taken to compute matrix multiplication
%   for sizes nxn where n = 1, 2, 4, 8, 16, 64, 128
% Calls testmult.m
% If mode == 1, plot naive & matlab multiplications
% If mode == 2, plot naive & strassen multiplications
% If mode == 3, plot naive & matlab & strassen multiplications
function plotmult(mode)

    if ((mode ~= 1) && (mode ~= 2) && (mode ~= 3)) % Verify mode is valid
        fprintf('Please enter a mode.\nmode = 1 to plot naive & matlab multiplication\nmode = 2 to plot naive & strassen multiplication\nmode = 3 to plot all multiplication')
        return
    end

    % Preallocate memory space
    naiveT = zeros(1,8);
    matlabT = zeros(1,8);
    strassenT = zeros(1,8);
    j = 1;
    x = 2.^[0:7];
    for i = x(1:end)
        [naiveT(j), matlabT(j), strassenT(j)] = testmult(i, mode);
        j = j + 1;
    end
    
    % DEBUG
    % format long e;
    % x
    % naiveT
    % matlabT
    % strassenT
    
    figure
    if (mode == 1) % naive & matlab
        plot(x,naiveT,'-k', x,matlabT,'-r')
        legend('naive', 'matlab', 'Location','northwest')
        title('Time Plot of Naive and Matlab Multiplications')
    elseif (mode == 2) % naive & strassen
        plot(x,naiveT,'-k', x,strassenT,'-b')
        legend('naive', 'strassen', 'Location','northwest')
        title('Time Plot of Naive and Strassen Multiplications')
    else % all
        plot(x,naiveT,'-k', x,matlabT,'-r', x,strassenT,'-b')
        legend('naive', 'matlab', 'strassen', 'Location','northwest')
        title('Time Plot of Naive, Matlab, and Strassen Multiplications')
    end

end

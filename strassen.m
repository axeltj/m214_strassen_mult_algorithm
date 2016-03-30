% Group:
% Christian Axel
% Erinjen Lin
% Namik Yarman
% Amaarah Johnson

% Recursive function that computes the matrix product AB using Strassen's algorithm.
%   Input: two matrices of size 2^n x 2^n
%   Output: one matrix of size 2^n x 2^n
function C = strassen( A, B )
    sizeN = size(A);
    sizeN = sizeN(1); % sizeN = n
    
    % Base case: size of A and B == 1x1
    if (sizeN == 1)
        C = A(1,1) * B(1,1);
    else
        % Divide A and B into submatrices
        sizeN = sizeN/2;
        A11 = A(1:sizeN, 1:sizeN);
        A12 = A(1:sizeN, (sizeN+1):end);
        A21 = A((sizeN+1):end, 1:sizeN);
        A22 = A((sizeN+1):end, (sizeN+1):end);
        B11 = B(1:sizeN, 1:sizeN);
        B12 = B(1:sizeN, (sizeN+1):end);
        B21 = B((sizeN+1):end, 1:sizeN);
        B22 = B((sizeN+1):end, (sizeN+1):end);
        
        % Compute M1, M2, ... M7
        M1 = strassen(A11 + A22, B11 + B22);
        M2 = strassen(A21 + A22, B11);
        M3 = strassen(A11, B12 - B22);
        M4 = strassen(A22, B21 - B11);
        M5 = strassen(A11 + A12, B22);
        M6 = strassen(A21 - A11, B11 + B12);
        M7 = strassen(A12 - A22, B21 + B22);
        
        % Compute C11, C12, C21, and C22
        C11 = M1 + M4 - M5 + M7;
        C12 = M3 + M5;
        C21 = M2 + M4;
        C22 = M1 - M2 + M3  + M6;
        C = [ C11, C12; C21, C22 ]; % C is returned
        
    end
    
end
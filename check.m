% Checks if the strassen algorithm is correct by
%   generating a random A and B and comparing the results of strassen(A,B)
%   and A*B.

% For integers
A = floor(100.*rand(128));
B = floor(100.*rand(128));

% Using non-integers will cause rounding.
% A = rand(64);
% B = rand(64);

C = A*B;
D = strassen(A,B);

if (C == D)
    disp ('algorithm was correct')
else
    disp ('algorithm was incorrect')
end

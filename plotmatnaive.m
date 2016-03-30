% Plots the times taken to compute the matrix multiplication for sizes nxn
%	where n = 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192
%	Only plots times of NAIVE and MATLAB multiplications.
function plotmatnaive()
	
	% Allocate memory space
	naiveT = zeros(1,14);
	matlabT = zeros(1,14);
	x = 2.^[0:13];
	j = 1;
	format long e;

	for i = x(1:end)
		M1 = rand(i,i);
		M2 = rand(i,i);

		t1 = cputime;
		% The naive multiplication algorithm
      	prod1 = zeros(i,i);
      	for i = 1 : i
        	for j = 1 : i
            	newent = 0;
              	for k = 1 : i
                	newent = newent + M1(i,k)*M2(k,j);
              	end
              	prod1(i,j) = newent;
          	end
      	end
      	t2 = cputime;

      	% MATLAB multiplication
      	prod2 = M1*M2;
      	t3 = cputime;

      	naiveT(j) = t2-t1;
      	matlabT(j) = t3-t2;

      	j = j + 1;
    end

    figure
    plot (x, naiveT, '-b', x, matlabT, '-r')
    legend('naive', 'matlab', 'Location','northwest')
    title('Time Plot of Naive and Matlab Multiplications')

end
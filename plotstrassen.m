% Plots the times taken to compute the matrix multiplication for sizes nxn
%	where n = 1, 2, 4, 8, 16, 32, 64, 128
%	Only plots times of the STRASSEN ALGORITHM
function plotstrassen()
	
	% Allocate memory space
	strassenT = zeros(1,14);
	x = 2.^[0:7];
	j = 1;
	format long e;

	for i = x(1:end)
		M1 = rand(i,i);
		M2 = rand(i,i);

		t1 = cputime;
		% Strassen multiplication algorithm
		prod = strassen(M1, M2);
		t2 = cputime;

		strassenT(j) = t2-t1;

		j = j + 1;
	end
	
	figure
	plot (x, strassenT, '-b')
	legend('strassen', 'Location','northwest')
	title('Time Plot of Strassen Multiplication Algorithm')

end
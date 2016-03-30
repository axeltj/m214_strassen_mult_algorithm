Linear Algebra (MATH 214) Project
Testing the effectiveness of the strassen algorithm compared to the naive method and the native MATLAB matrix multiplicator.

FILES:
strassen.m : Strassen algorithm (already tested for correctness)
check.m : checks if the strassen algorithm is correct for random matrices
plotmult.m : plots times of Naive, Native Matlab, and Strassen algorithm
testmult.m : helper function for plotmult.m. Don't run this function alone.
strassen.cpp : Strassen & Naive algorithm in C++ (throws bad::alloc, because PC would just go out of memory :( So don't use this.)
plotmatnaive.m : Standalone script to plot ONLY naive and Matlab multiplication timings.
plotstrassen.m : Script to plot ONLY strassen algorithm timings. Requires strassen.m

MATLAB is incredibly slow in executing recursive functions.
I've tried optimizing the strassen algorithm, but algorithm is still too slow.
The algorithm takes about ~9 seconds multiplying matrices of size 128x128 but beyond that timing mutliplies tenfold.
Sources say that Strassen's should be faster than the naive method for very large matrices ( > 1000x1000 ), but we couldn't test them.
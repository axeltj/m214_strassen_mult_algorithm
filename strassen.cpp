#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

/* Calculates multiplication using naive method.
 * Creates vector pairs of sizes 2^n and performs multiplication on each.
 * Records times taken to perform multiplication in vector "times"
 */
void naive(vector<double>& times) {
	vector< vector<int> > vec1;
	vector< vector<int> > vec2;
	vector< vector<int> > vec_result;
	vector<int> temp_vec;
	int temp_i;

	for (int i = 1; i <= 1024; i *= 2) {
		cout << "Now size " << i << endl;
		vec1.clear();
		vec2.clear();
		vec_result.clear();
		for (int j = 0; j < i; j++) {
			vec1.push_back(temp_vec);
			vec2.push_back(temp_vec);
			vec_result.push_back(temp_vec);
			for (int k = 0; k < i; k++) {
				vec1[j].push_back(rand()%100);
				vec2[j].push_back(rand()%100);
				vec_result[j].push_back(0);
			}
		}
		cout << "Calculating now" << endl;
		clock_t begin = clock();
		for (int row = 0; row < i; row++) {
			for (int col = 0; col < i; col++) {
				temp_i = 0;
				for (int it = 0; it < i; it++) {
					temp_i += vec1[row][it] * vec2[it][col];
				}
				vec_result[row][col] = temp_i;
			}
		}
		clock_t end = clock();
		times.push_back( double(end-begin)/CLOCKS_PER_SEC );
		cout << "Done. Time taken = " << times.back() << endl;
	}
	return;
}

/* Helper function to add two vectors. Returns a 2D vector */
vector< vector<int> > add_helper(const vector< vector<int> >& A, const vector< vector<int> >& B) {
	vector< vector<int> > added;
	vector<int> temp_vec;
	unsigned vec_size = A.size();
	for (int i = 0; i < vec_size; i++) {
		added.push_back(temp_vec);
		for (int j = 0; j < vec_size; j++) {
			added[i].push_back(A[i][j] + B[i][j]);
		}
	}
	return added;
}
/* Helper function to subtract two vectors (A - B). Returns a 2D vector */
vector< vector<int> > sub_helper(const vector< vector<int> >& A, const vector< vector<int> >& B) {
	vector< vector<int> > added;
	vector<int> temp_vec;
	unsigned vec_size = A.size();
	for (int i = 0; i < vec_size; i++) {
		added.push_back(temp_vec);
		for (int j = 0; j < vec_size; j++) {
			added[i].push_back(A[i][j] - B[i][j]);
		}
	}
	return added;
}

/* Recursive function. Does NOT modify input vectors, but modifies resulting vector.
 * Returns the resulting product of the two input vectors */
vector< vector<int> > strassen_recursive(const vector< vector<int> > A, const vector< vector<int> > B) {
	cout << "Calling Recursive for matrices " << endl;
	for (int x = 0; x < A.size(); x++) {
		for (int y = 0; y < A[0].size(); y++) {
			cout << A[x][y] << " ";
		}
		cout << endl;
	}
	cout << "and" << endl;
	for (int x = 0; x < B.size(); x++) {
		for (int y = 0; y < B[0].size(); y++) {
			cout << B[x][y] << " ";
		}
		cout << endl;
	}
	unsigned N = A.size();
	vector< vector<int> > C;
	vector<int> temp_vec;
	int i, j; // i = row, j = col
	// Base case: size of A and B = 1x1
	if (N == 1) {
		C.push_back(temp_vec);
		C[0].push_back(A[0][0] * B[0][0]);
		// return C
	}
	else {
		cout << "Dividing A and B into submatrices..." << endl;
		// Divide A and B into submatrices
		int N2 = N/2;
		vector< vector<int> > A11;
		for (i = 0; i < N2; i++) {
			A11.push_back(temp_vec);
			for (j = 0; j < N2; j++) {
				A11[i].push_back(A[i][j]);
			}
		}
		cout << "Done A11:" << endl;
		for (int x = 0; x < A11.size(); x++) {
			for (int y = 0; y < A11[0].size(); y++) {
				cout << A11[x][y] << " ";
			}
			cout << endl;
		}
		vector< vector<int> > A12;
		for (i = 0; i < N2; i++) {
			A12.push_back(temp_vec);
			for (j = N2; j < N; j++) {
				A12[i].push_back(A[i][j]);
			}
		}
		cout << "Done A12:" << endl;
		for (int x = 0; x < A12.size(); x++) {
			for (int y = 0; y < A12[0].size(); y++) {
				cout << A12[x][y] << " ";
			}
			cout << endl;
		}
		vector< vector<int> > A21;
		for (i = N2; i < N; i++) {
			A21.push_back(temp_vec);
			for (j = 0; j < N2; j++) {
				A21[i].push_back(A[i][j]);
			}
		}
		cout << "Done A21:" << endl;
		for (int x = 0; x < A21.size(); x++) {
			for (int y = 0; y < A21[0].size(); y++) {
				cout << A21[x][y] << " ";
			}
			cout << endl;
		}
		vector< vector<int> > A22;
		for (i = N2; i < N; i++) {
			A22.push_back(temp_vec);
			for (j = N2; j < N; j++) {
				A22[i].push_back(A[i][j]);
			}
		}
		cout << "Done A22:" << endl;
		for (int x = 0; x < A22.size(); x++) {
			for (int y = 0; y < A22[0].size(); y++) {
				cout << A22[x][y] << " ";
			}
			cout << endl;
		}
		vector< vector<int> > B11;
		for (i = 0; i < N2; i++) {
			B11.push_back(temp_vec);
			for (j = 0; j < N2; j++) {
				B11[i].push_back(B[i][j]);
			}
		}
		vector< vector<int> > B12;
		for (i = 0; i < N2; i++) {
			B12.push_back(temp_vec);
			for (j = N2; j < N; j++) {
				B12[i].push_back(B[i][j]);
			}
		}
		vector< vector<int> > B21;
		for (i = N2; i < N; i++) {
			B21.push_back(temp_vec);
			for (j = 0; j < N2; j++) {
				B21[i].push_back(B[i][j]);
			}
		}
		vector< vector<int> > B22;
		for (i = N2; i < N; i++) {
			B22.push_back(temp_vec);
			for (j = N2; j < N; j++) {
				B22[i].push_back(B[i][j]);
			}
		}
		cout << "Computing M1...M7" << endl;
		// Compute M1, M2,.....M7
		vector< vector<int> > M1 = strassen_recursive(add_helper(A11, A22), add_helper(B11, B22));
		vector< vector<int> > M2 = strassen_recursive(add_helper(A21, A22), B11);
		vector< vector<int> > M3 = strassen_recursive(A11, sub_helper(B12, B22));
		vector< vector<int> > M4 = strassen_recursive(A22, sub_helper(B21, B11));
		vector< vector<int> > M5 = strassen_recursive(add_helper(A11, A12), B22);
		vector< vector<int> > M6 = strassen_recursive(sub_helper(A21, A11), add_helper(B11, B12));
		vector< vector<int> > M7 = strassen_recursive(sub_helper(A12, A22), add_helper(B21, B22));
		cout << "Computing C11...C22" << endl;
		// Compute C11, C12, C21, and C22
		vector< vector<int> > C11 = add_helper(sub_helper(add_helper(M1, M4), M5), M7);
		vector< vector<int> > C12 = add_helper(M3, M5);
		vector< vector<int> > C21 = add_helper(M2, M4);
		vector< vector<int> > C22 = add_helper(add_helper(sub_helper(M1, M2), M3), M6);
		cout << "Combining to form C..." << endl;
		// Combine to form C
		for (int i = 0; i < N2; i++) { // for the first N2 rows of C
			C.push_back(temp_vec);
			for (int j = 0; j < N2; j++) { // add every col of C11
				C[i].push_back(C11[i][j]);
			}
			for (int j = 0; j < N2; j++) { // add every col of C12
				C[i].push_back(C12[i][j]);
			}
		}
		for (int i = 0; i < N2; i++) { // for the last N2 rows of C
			C.push_back(temp_vec);
			for (int j = 0; j < N2; j++) { // add every col of C21
				C[i].push_back(C21[i][j]);
			}
			for (int j = 0; j < N2; j++) { // add every col of C22
				C[i].push_back(C22[i][j]);
			}
		}
		// return C
	}
	cout << "Returning C" << endl;
	return C;
}

/* Calculates multiplication using strassen algorithm */
void strassen(vector<double>& times) {
	vector< vector<int> > vec1;
	vector< vector<int> > vec2;
	vector< vector<int> > result;
	vector<int> temp_vec;
	for (int i = 1; i <= 1024; i *= 2) {
		cout << "Now size " << i << endl;
		vec1.clear();
		vec2.clear();
		result.clear();
		for (int j = 0; j < i; j++) {
			vec1.push_back(temp_vec);
			vec2.push_back(temp_vec);
			for (int k = 0; k < i; k++) {
				vec1[j].push_back(rand()%100);
				vec2[j].push_back(rand()%100);
			}
		}
		cout << "Calculating now" << endl;
		clock_t begin = clock();
		result = strassen_recursive(vec1, vec2); // recursive function
		clock_t end = clock();
		times.push_back( double(end-begin)/CLOCKS_PER_SEC );
		cout << "Done. Time taken = " << times.back() << endl;
	}
	return;
}

/* Create pairs of vectors of size 2^n for n = 1, 2,....10
 *	that contains random numbers, then
 *	runs a chosen multiplication algorithm,
 *	and records the time taken to solve the matrix multipication
 */
int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Usage:\n./strassen -h\n./strassen naive\n./strassen strassen" << endl;
		exit(1);
	}
	else {
		if (!strcmp(argv[1], "naive")) {
			std::ofstream outf;
			outf << std::fixed << std::setprecision(5);
			outf.open("naive_time.txt");
			vector<double> times;
			naive(times);
			for (int i = 0; i < times.size(); i++) {
				outf << times[i] << endl;
			}
			outf.close();
		}
		else if (!strcmp(argv[1], "strassen")) {
			std::ofstream outf;
			outf << std::fixed << std::setprecision(5);
			outf.open("strassen_time.txt");
			vector<double> times;
			strassen(times);
			for (int i = 0; i < times.size(); i++) {
				outf << times[i] << endl;
			}
			outf.close();
		}
		else {
			cout << "Usage:\n./strassen -h\n./strassen naive\n./strassen strassen" << endl;
			exit(1);
		}
	}
	return 0;
}
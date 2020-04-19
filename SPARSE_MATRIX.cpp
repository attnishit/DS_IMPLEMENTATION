/*
1. A matrix is sparse if most elements of the matrix are zero. We might store a large sparse
matrix (to save space) as a list of triples (i, j, value) where (i, j) is a position and value is
a non-zero value. We may represent the list in an array A[t, 3], where t is an upper bound
on the number of non-zero elements. Further, we may maintain the list sorted so that the
row numbers are increasing and within a row the column numbers are increasing. Design
algorithms to i) transpose a sparse matrix ii) addition two sparse matrices and iii) multiply
two sparse matrices.
*/
#include <bits/stdc++.h>
using namespace std;

class MATRIX { 
	const static int MAX = 100; 
	int **data; 
	int row, col; 
	int len; 

public: 
	MATRIX(int r, int c) { 
		row = r; 
		col = c; 
		len = 0; 
		data = new int *[MAX]; 
		for (int i = 0; i < MAX; i++) 
			data[i] = new int[3]; 
	} 
	void insert(int r, int c, int val) 
	{ 

		if (r > row || c > col) 
		{ 
			cout << "Invalid"; 
		} 
		else
		{ 
			data[len][0] = r; 
			data[len][1] = c; 
			data[len][2] = val; 
			len++; 
		} 
	} 

	MATRIX transpose() { 
		MATRIX result(col, row); 

		result.len = len; 
		int *count = new int[col + 1]; 
		for (int i = 1; i <= col; i++) 
			count[i] = 0; 

		for (int i = 0; i < len; i++) 
			count[data[i][1]]++; 

		int *index = new int[col + 1]; 
		index[0] = 0; 
		for (int i = 1; i <= col; i++) 

			index[i] = index[i - 1] + count[i - 1]; 

		for (int i = 0; i < len; i++) { 
			int rpos = index[data[i][1]]++; 
			result.data[rpos][0] = data[i][1]; 
			result.data[rpos][1] = data[i][0]; 
			result.data[rpos][2] = data[i][2]; 
		} 
		return result; 
	} 

	void MULTIPLY(MATRIX b) { 
		if (col != b.row){ 
			cout << "Can't multiply, Invalid dimensions"; 
			return; 
		} 
		b = b.transpose(); 
		int apos, bpos; 
		MATRIX result(row, b.row); 
		for (apos = 0; apos < len;) { 
			int r = data[apos][0]; 
			for (bpos = 0; bpos < b.len;) { 
				int c = b.data[bpos][0]; 
				int tempa = apos; 
				int tempb = bpos; 
				int sum = 0; 
				while (tempa < len && data[tempa][0] == r && tempb < b.len && b.data[tempb][0] == c) { 
					if (data[tempa][1] < b.data[tempb][1]) 
						tempa++; 

					else if (data[tempa][1] > b.data[tempb][1]) 
						tempb++; 
					else
						sum += data[tempa++][2]*b.data[tempb++][2]; 
				} 
				if (sum != 0) 
					result.insert(r, c, sum); 

				while (bpos < b.len && b.data[bpos][0] == c) 

					bpos++; 
			} 
			while (apos < len && data[apos][0] == r) 
				apos++; 
		} 
		result.display(); 
	} 
	void ADDITION(MATRIX b) { 
		if (row != b.row || col != b.col) { 
			cout << "Matrices can't be added"; 
		} 
		else{ 
			int apos = 0, bpos = 0; 
			MATRIX result(row, col); 

			while (apos < len && bpos < b.len) { 
				if (data[apos][0] > b.data[bpos][0] || (data[apos][0] == b.data[bpos][0] && data[apos][1] > b.data[bpos][1])) { 
					result.insert(b.data[bpos][0], 
								b.data[bpos][1], 
								b.data[bpos][2]); 

					bpos++; 
				} 
				else if (data[apos][0] < b.data[bpos][0] || (data[apos][0] == b.data[bpos][0] && data[apos][1] < b.data[bpos][1])) { 
					result.insert(data[apos][0], 
								data[apos][1], 
								data[apos][2]); 

					apos++; 
				} 
				else{ 
					int ADDITIONedval = data[apos][2] + 
								b.data[bpos][2]; 

					if (ADDITIONedval != 0) 
						result.insert(data[apos][0], 
									data[apos][1], 
									ADDITIONedval); 
					apos++; 
					bpos++; 
				} 
			} 
			while (apos < len) 
				result.insert(data[apos][0], 
							data[apos][1], 
							data[apos++][2]); 

			while (bpos < b.len) 
				result.insert(b.data[bpos][0], 
							b.data[bpos][1], 
							b.data[bpos++][2]); 
			result.display(); 
		} 
	} 
	void display() { 
		cout << "\nDimension: " << row << "x" << col; 
		cout << "\nSparse Matrix: \nRow\tColumn\tValue\n"; 

		for (int i = 0; i < len; i++) { 
			cout << data[i][0] << "\t " << data[i][1] << "\t " << data[i][2] << endl; 
		} 
	} 
}; 


int main() { 

	MATRIX a(5, 5); 
	MATRIX b(5, 5); 

	a.insert(1, 2, 10); 
	a.insert(1, 4, 12); 
	a.insert(3, 3, 5); 
	a.insert(4, 1, 15); 
	a.insert(4, 2, 12); 
	b.insert(1, 3, 8); 
	b.insert(2, 4, 23); 
	b.insert(3, 3, 9); 
	b.insert(4, 1, 20); 
	b.insert(4, 2, 25); 

	cout << "Addition: "; 
	a.ADDITION(b); 
	cout << "\nMultiplication: "; 
	a.MULTIPLY(b); 
	cout << "\nTranspose: "; 
	MATRIX atranspose = a.transpose(); 
	atranspose.display(); 
	return 0;
} 

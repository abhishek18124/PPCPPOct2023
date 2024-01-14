/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>
#include<algorithm>

using namespace std;

void sortDiagonal(int mat[][10], int m, int n, int i, int j) {

	int len = min(m - i, n - j);
	int arr[len]; // to store the diagonal elements

	for (int k = 0; k < len; k++) {

		arr[k] = mat[i + k][j + k];

	}

	sort(arr, arr + len);

	for (int k = 0; k < len; k++) {

		mat[i + k][j + k] = arr[k];

	}

}

void sortMatrix(int mat[][10], int m, int n) {

	// sort all the diagonals that start at the (0, j)th index

	for (int j = 0; j <= n - 1; j++) {

		sortDiagonal(mat, m, n, 0, j);

	}


	// sort all the diagonals that start at the (i, 0)th index

	for (int i = 1; i <= m - 1; i++) {

		sortDiagonal(mat, m, n, i, 0);

	}

}


int main() {

	int mat[][10] = {
		{50, 80, 20},
		{90, 10, 70},
		{60, 30, 40}
	};

	int m = 3;
	int n = 3;

	sortMatrix(mat, n, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
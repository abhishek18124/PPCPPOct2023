/*

	Constraints

	0 < m, n <= 10

	here, m denotes the no. of rows in the given 2D array
	      n denotes the no. of cols in the given 2D array

*/

#include<iostream>

using namespace std;

int main() {

	int arr[10][10];

	int m;
	cout << "Enter the no. of row : ";
	cin >> m;

	int n;
	cout << "Enter the no. of columns : ";
	cin >> n;

	// read mxn values into the 2D array

	for (int i = 0; i <= m - 1; i++) {

		// read 'n' valus in the ith row

		for (int j = 0; j <= n - 1; j++) {

			cin >> arr[i][j];

		}

	}

	// print mxn values of the 2D array

	for (int i = 0; i <= m - 1; i++) {

		// print the 'n' values in the ith row

		for (int j = 0; j <= n - 1; j++) {

			cout << arr[i][j] << " ";

		}

		cout << endl;

	}

	return 0;
}



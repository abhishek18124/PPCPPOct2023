#include<iostream>

using namespace std;

int main() {

	// int m;
	// cin >> m;
	int m = 20;

	int arr[m + 1];

	for (int i = 0; i <= m; i++) {
		arr[i] = 1;
	}

	arr[0] = 0;
	arr[1] = 0;

	// for (int i = 2; i <= m; i++) {

	// 	if (arr[i] == 1) {

	// 		// i is a prime numbers therefore cancel out its multiples

	// 		for (int j = 2 * i; j <= m; j = j + i) {

	// 			arr[j] = 0;

	// 		}

	// 	}

	// }

	// for (int i = 2; i <= m; i++) {

	// 	if (arr[i] == 1) {

	// 		// i is a prime numbers therefore cancel out its multiples

	// 		for (int j = i * i; j <= m; j = j + i) {

	// 			arr[j] = 0;

	// 		}

	// 	}

	// }

	for (int i = 2; i * i <= m; i++) { // condition i <= sqrt(m)

		if (arr[i] == 1) {

			// i is a prime numbers therefore cancel out its multiples

			for (int j = i * i; j <= m; j = j + i) {

				arr[j] = 0;

			}

		}

	}

	for (int i = 2; i <= m; i++) {

		if (arr[i] == 1) {
			cout << i << " ";
		}

	}

	cout << endl;

	return 0;
}
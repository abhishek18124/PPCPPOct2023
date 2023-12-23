// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	int csum[101]; // based on the constraints
	csum[0] = 0;

	for (int i = 1; i <= n; i++) {
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	int cnt = 0;

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			int sij = csum[j + 1] - csum[i];
			if (sij % n == 0) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;


	return 0;
}
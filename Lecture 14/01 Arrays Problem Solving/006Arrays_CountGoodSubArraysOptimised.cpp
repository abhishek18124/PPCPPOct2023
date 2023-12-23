// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	// time : 2n steps ~ O(n)
	// space : n due to freq[] ~ O(n)

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	int freq[100]; // based on the constraints
	memset(freq, 0, sizeof(freq));

	freq[0] = 1;
	int csum = 0;

	for (int i = 0; i < n; i++) {
		csum += arr[i];
		freq[((csum % n) + n) % n]++;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int xi = freq[i];
		if (xi >= 2) {
			cnt += xi * (xi - 1) / 2;
		}
	}

	cout << cnt << endl;

	return 0;
}
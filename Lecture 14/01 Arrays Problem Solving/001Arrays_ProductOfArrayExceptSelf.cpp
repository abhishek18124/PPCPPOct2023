// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	// // time : O(n^2)

	// int answer[100]; // based on constraints

	// for (int i = 0; i < n; i++) {

	// 	// compute answer[i]

	// 	int l_i = 1; // 0 to i-1
	// 	for (int j = 0; j <= i - 1; j++) {
	// 		l_i = l_i * nums[j];
	// 	}

	// 	int r_i = 1; // i+1 to n-1
	// 	for (int j = i + 1; j <= n - 1; j++) {
	// 		r_i = r_i * nums[j];
	// 	}

	// 	answer[i] = l_i * r_i;

	// }

	// time : O(n)
	// space: O(n)

	int l[100]; // based on constraints
	l[0] = 1;
	for (int i = 1; i <= n - 1; i++) {
		l[i] = l[i - 1] * nums[i - 1];
	}

	int r[100]; // based on constraints
	r[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		r[i] = r[i + 1] * nums[i + 1];
	}

	int answer[100]; // based on constraints
	for (int i = 0; i <= n - 1; i++) {
		answer[i] = l[i] * r[i];
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;

	return 0;
}
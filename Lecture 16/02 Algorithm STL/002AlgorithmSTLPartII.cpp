#include<iostream>
#include<algorithm>

using namespace std;

// return true if you want 'a' to be ordered before 'b' in the sorted sequence otherwise return false

bool compartor(int a, int b) {

	// if (a > b) {

	// 	// we want 'a' to be ordered before 'b' if we are sorting in decreasing order

	// 	return true;

	// }

	// return false;

	return a > b;

}

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// sort(arr, arr + n, compartor);

	// sort(arr, arr + n, &compartor);

	sort(arr, arr + n, greater<int>());

	// greater<int> var; // function Object / functor

	// sort(arr, arr + n, var);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;


	return 0;
}

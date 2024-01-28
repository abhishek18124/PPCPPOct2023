#include<iostream>
#include<vector>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool comparator(int a, int b) {
	if (a > b) {
		// you want a to be ordered before b since we are sorting in dec. order
		return true;
	}

	return false;
}

int main() {

	// 1. creating a vector using initialiser list

	vector<int> v = {1, 0, 2, 4, 3};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 2. sorting a vector in the decreasing order

	// sort(v.rbegin(), v.rend());

	// sort(v.begin(), v.end(), greater<int>());

	// greater<int> funObj;

	// sort(v.begin(), v.end(), funObj);

	sort(v.begin(), v.end(), comparator);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
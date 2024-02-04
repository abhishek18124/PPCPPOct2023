#include<iostream>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {

	int n = arr.size();

	int s = 0;
	int e = n - 1;

	while (s < e) {

		int m1 = s + (e - s) / 3;
		int m2 = e - (e - s) / 3;

		if (arr[m1] > arr[m2]) {
			// reduce the search space from [s, e] to [s, m2-1]
			e = m2 - 1;
		} else {
			// reduce the search space from [s, e] to [m1+1, e]
			s = m1 + 1;
		}

	}

	return arr[s]; // arr[e]

}

int main() {

	vector<int> arr = {0, 1, 3, 10, 3, 1, 0};
	cout << peakIndexInMountainArray(arr) << endl;

	return 0;
}
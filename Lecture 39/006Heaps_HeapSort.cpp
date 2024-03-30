/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	// fixes the max heap property at ith index node

	int maxIdx = i;

	int leftIdx = 2 * i + 1;
	if (leftIdx < n and v[leftIdx] > v[maxIdx]) {
		maxIdx = leftIdx;
	}

	int rightIdx = 2 * i + 2;
	if (rightIdx < n and v[rightIdx] > v[maxIdx]) {
		maxIdx = rightIdx;
	}

	if (maxIdx != i) {

		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);

	}

}

// time heapsort = O(n + nlogn) ~ O(nlogn)
// space - O(logn) due function call used in heapify if it is recursive
// but if you impl. heapify iteratively (homework) then space for heapsort will be O(1)

int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// 1. transform v[] into a maxHeap - O(n)

	for (int i = n - 1; i >= 0; i--) {

		heapify(v, n, i);

	}

	int heapsize = n;

	// 2. transform maxHeap into sorted arr - (n-1)*logn ~ O(nlogn)

	while (heapsize > 1) {

		swap(v[0], v[heapsize - 1]); // const
		heapsize--; // const
		heapify(v, heapsize, 0); // logn since we are calling heapify on the root node

	}


	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}

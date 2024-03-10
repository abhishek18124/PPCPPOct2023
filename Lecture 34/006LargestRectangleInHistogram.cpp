#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> nearestSmallerElementToTheLeft(int A[], int n) {

	stack<int> s; // index
	vector<int> v; // to store output

	for (int i = 0; i < n ; i++) {

		// find the index of nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any smaller elements to its left
			v.push_back(-1);
		} else {
			// A[s.top()] is the nearest smaller element to the left of A[i]
			v.push_back(s.top());
		}

		s.push(i);

	}

	return v;

}

vector<int> nearestSmallerElementToTheRight(int A[], int n) {

	stack<int> s; // index
	vector<int> v; // to store output

	for (int i = n - 1; i >= 0 ; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any smaller elements to its right
			v.push_back(n);
		} else {
			// A[s.top()] is the nearest smaller element to the right of A[i]
			v.push_back(s.top());
		}

		s.push(i);

	}

	reverse(v.begin(), v.end());

	return v;

}


// time : 3n ~ O(n)
// space: n due to stacks

int largestRectangleArea(int h[], int n) {

	vector<int> v1 = nearestSmallerElementToTheRight(h, n); // n
	vector<int> v2 = nearestSmallerElementToTheLeft(h, n); // n

	int maxSoFar = 0;

	for (int i = 0; i < n; i++) { // n

		// for the height h[i], find the best width

		int best_width = v1[i] - v2[i] - 1;
		int best_area = h[i] * best_width;

		maxSoFar = max(maxSoFar, best_area);

	}

	return maxSoFar;

}

int main() {

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	cout << largestRectangleArea(h, n) << endl;

	return 0;
}
#include<iostream>
#include<stack>

using namespace std;

// time : O(n) [worst-case {1, 2, 3, 4, 5} n push + n-1 pop ~ 2n ops ~ O(n) space ~ O(1)]
// space: O(n) [worst-case {5, 4, 3, 2, 1} n push no pops ~ n opts time ~ O(n) space ~ O(n)]

vector<int> nearestGreaterElementToTheLeft(int A[], int n) {

	stack<int> s;
	vector<int> v; // to store output

	for (int i = 0; i < n; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			v.push_back(-1);
		} else {
			v.push_back(s.top());
		}

		s.push(A[i]);

	}

	return v;

}

int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestGreaterElementToTheLeft(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
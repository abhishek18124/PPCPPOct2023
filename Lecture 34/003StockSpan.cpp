#include<iostream>
#include<stack>

using namespace std;

vector<int> stockSpan(int A[], int n) {

	vector<int> v;

	stack<pair<int, int>> s; // <element, index>

	for (int i = 0; i < n; i++) {

		// find the index of the nearest greater element to the left of A[i]

		while (!s.empty() and s.top().first <= A[i]) { // s.top() = <element, index>
			s.pop();
		}

		int j;

		if (s.empty()) {
			// A[i] doesn't have any greater elements to its left
			j = -1;
		} else {
			// s.top().first is the nearest greater element to the left of A[i]
			j = s.top().second;
		}

		v.push_back(i - j); // span for the ith day is i-j

		s.push({A[i], i}); // s.push(make_pair(A[i], i))

	}

	return v;

}

vector<int> stockSpanUsingIndices(int A[], int n) {

	vector<int> v;

	stack<int> s; // <index>

	for (int i = 0; i < n; i++) {

		// find the index of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) { // s.top() = index
			s.pop();
		}

		int j;

		if (s.empty()) {
			// A[i] doesn't have any greater elements to its left
			j = -1;
		} else {
			// s.top() is the index of nearest greater element to the left of A[i]
			j = s.top();
		}

		v.push_back(i - j); // span for the ith day is i-j

		s.push(i);

	}

	return v;

}


int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = stockSpan(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	v = stockSpanUsingIndices(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
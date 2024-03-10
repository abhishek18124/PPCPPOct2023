#include<iostream>
#include<stack>
#include<forward_list>

using namespace std;

// time : O(n)
// space: O(n)

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


int main() {

	int A[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestSmallerElementToTheLeft(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}
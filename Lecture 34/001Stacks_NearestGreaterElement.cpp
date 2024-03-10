#include<iostream>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n)

vector<int> nearestGreaterElementToTheRight(int A[], int n) {

	stack<int> s;
	vector<int> v; // to store output

	for (int i = n - 1; i >= 0 ; i--) {

		// find the nearest greater element to the right of A[i]

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

	reverse(v.begin(), v.end());

	return v;

}


int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestGreaterElementToTheRight(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;



	return 0;
}
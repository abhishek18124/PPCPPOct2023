#include<iostream>
#include<stack>
#include<forward_list>

using namespace std;

// time : O(n)
// space: O(n)

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


int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);


	vector<int> v = nearestSmallerElementToTheRight(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}
/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>

using namespace std;

int f(int n, int k, int i) {

	// base case

	if (i == n) {
		// you've reached the nth step i.e. you've found the path
		return 1;
	}

	if (i > n) { // now, you are doing addition rec. calls
		// you've gone outside the ladder
		return 0;
	}

	// recursive case

	// count the no. of ways to go from i to n

	// decide the next step / next jump

	// i to i+1 => count the no. of ways to go from i+1 to n
	// i to i+2 => count the no. of ways to go from i+2 to n
	// i to i+3 => count the no. of ways to go from i+3 to n
	// ...
	// i to i+k => count the no. of ways to go from i+k to n

	int cnt = 0;

	for (int j = 1; j <= k; j++) {
		// take a jump of size j
		cnt += f(n, k, i + j);

	}
	return cnt;


}

int main() {

	int n = 4;
	int k = 3;

	cout << f(n, k, 0) << endl;

	return 0;
}
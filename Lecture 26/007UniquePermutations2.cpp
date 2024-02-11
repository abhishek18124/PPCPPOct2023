/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) {

		cout << inp << endl;
		return;

	}

	// recursive case

	// generate the permutations for inp[i...n-1]

	// or

	// take decisions for the remaining n-i positions from i to n-1

	// decide for the ith position which char. is assigned to it

	for (int j = i; j < n; j++) {

		// can I use the char. at the jth index for the ith pos ?

		bool flag = true; // assume you can use the jth option at the ith pos

		for (int k = j + 1; k < n; k++) {
			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {

			// assign the char. at the jth index to the ith pos

			swap(inp[i], inp[j]);
			f(inp, n, i + 1);
			swap(inp[i], inp[j]); // backtracking (undo)
		}

	}

}

// whenever for a single decision you've multiple options

// 1. your recursive algorithm will have a loop to iterate over those options

// 2. backtracking will always happen

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}

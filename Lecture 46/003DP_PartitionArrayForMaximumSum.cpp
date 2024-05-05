#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int helper(const vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {

		// you've built a valid partition

		return 0;

	}

	// recursive case

	// find the max. sum upon partitioning arr[i...n-1] in sub-arr of size <= k

	// decide the next cut

	int maxSoFar = INT_MIN;
	int max_ij = INT_MIN; // or arr[i]

	for (int j = i; j <= i + k - 1 and j < n; j++) {

		// make a cut at index j

		max_ij = max(max_ij, arr[j]);
		int sij = (j - i + 1) * max_ij;

		maxSoFar = max(maxSoFar, sij + helper(arr, n, k, j + 1));

	}

	return maxSoFar;

}

// time : O(n^2)
// space: O(n) due to dp[]

int helperBottomUp(vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);

	dp[n] = 0; // at the nth index of dp[] we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i) = // find the max. sum upon partitioning arr[i...n-1] in sub-arr of size <= k

		// decide the next cut

		int maxSoFar = INT_MIN;
		int max_ij = INT_MIN; // or arr[i]

		for (int j = i; j <= i + k - 1 and j < n; j++) {

			// make a cut at index j

			max_ij = max(max_ij, arr[j]);
			int sij = (j - i + 1) * max_ij;

			maxSoFar = max(maxSoFar, sij + dp[j + 1]);

		}

		dp[i] = maxSoFar;

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return helper(arr, n, k, 0);

	return helperBottomUp(arr, n, k);
}

int main() {

	vector<int> arr = {1, 2, 3, 4, 5, 6};
	int k = 1;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}
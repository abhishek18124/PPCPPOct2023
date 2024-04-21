/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int cnt1 = 0;

int helper(vector<int> prices, int i, int j, int y) {

	cnt1++;

	// base case

	if (i == j) {

		// find the max. profit from selling wins[i..i] or wines[j...j] st. from yth year which will be equal to n

		return prices[i] * y;

	}

	// recursive case

	// find the max. profit from selling wines[i...j] st. from the yth year

	// decide for the yth year

	// option 1 : sell the ith bottle of wine

	// option 2 : sell the jth bottle of wine

	return max(prices[i] * y + helper(prices, i + 1, j, y + 1),
	           prices[j] * y + helper(prices, i, j - 1, y + 1));

}

int cnt2 = 0;

int helperTopDown(vector<int> prices, int i, int j, int y, vector<vector<int>>& dp) {

	cnt2++;

	// lookup

	if (dp[i][j] != -1) {

		// you've already solved f(i, j)

		return dp[i][j];

	}

	// base case

	if (i == j) {

		// find the max. profit from selling wins[i..i] or wines[j...j] st. from yth year which will be equal to n

		return dp[i][j] = prices[i] * y;

	}

	// recursive case

	// find the max. profit from selling wines[i...j] st. from the yth year

	// decide for the yth year

	// option 1 : sell the ith bottle of wine

	// option 2 : sell the jth bottle of wine

	return dp[i][j] = max(prices[i] * y + helperTopDown(prices, i + 1, j, y + 1, dp),
	                      prices[j] * y + helperTopDown(prices, i, j - 1, y + 1, dp));

}

// time : O(n^2)
// space: O(n^2)

int helperBottomUp(vector<int> prices, int n) {

	vector <vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		// int j = i;
		// int y = n;
		// dp[i][j] = prices[i] * y;
		dp[i][i] = prices[i] * n;
	}

	for (int i = n - 2; i >= 0; i--) {

		for (int j = i + 1; j < n; j++) {

			// dp[i][j] = f(i, j)
			int y = n - j + i;
			dp[i][j] = max(y * prices[i] + dp[i + 1][j], y * prices[j] + dp[i][j - 1]);

		}

	}

	return dp[0][n - 1]; // at the 0,n-1th index of dp[][], we store f(0, n-1)

}

int main() {

	vector<int> prices = {2, 3, 5, 1, 4};
	int n = prices.size();

	cout << helper(prices, 0, n - 1, 1) << endl;

	vector<vector<int>> dp(n, vector<int>(n, -1));

	cout << helperTopDown(prices, 0, n - 1, 1, dp) << endl;

	cout << cnt1 << " " << cnt2 << endl;

	cout << helperBottomUp(prices, n) << endl;

	return 0;
}
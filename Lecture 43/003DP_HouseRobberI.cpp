#include<iostream>
#include<vector>

using namespace std;

// recursive implementation

int helper(vector<int>& nums, int n, int i) {

    // base case

    if (i == n || i == n + 1) {

        // find the max profit from houses[n...n-1] || houses[n+1...n-1]

        return 0;

    }

    // recursive case

    // find the maximum amount of money you can rob given a sequence of n-i houses [i...n-1] w/o alerting the police

    // decide for the ith house

    // option 1 : rob the ith house

    int robIthHouse = nums[i] + helper(nums, n, i + 2);

    // option 2 : don't rob the ith house

    int donotRobIthHouse = helper(nums, n, i + 1);

    return max(robIthHouse, donotRobIthHouse);

}

// time : O(n)
// space: O(n) due to function call stack and dp[]

int helperTopDown(const vector<int>& nums, int n, int i, vector<int>& dp) {

    // lookup

    if (dp[i] != -1) {

        // you already know the result of f(i)

        return dp[i];

    }

    // base case

    if (i == n || i == n + 1) {

        // find the max profit from houses[n...n-1] || houses[n+1...n-1]

        return dp[i] = 0;

    }

    // recursive case

    // find the maximum amount of money you can rob given a sequence of n-i houses [i...n-1] w/o alerting the police

    // decide for the ith house

    // option 1 : rob the ith house

    int robIthHouse = nums[i] + helperTopDown(nums, n, i + 2, dp);

    // option 2 : don't rob the ith house

    int donotRobIthHouse = helperTopDown(nums, n, i + 1, dp);

    return dp[i] = max(robIthHouse, donotRobIthHouse);

}

// time : O(n)
// space: O(n)

int helperBottomUp(const vector<int>& nums, int n) {

    vector<int> dp(n + 2);

    dp[n + 1] = dp[n] = 0;

    for (int i = n - 1;  i >= 0; i--) {

        // dp[i] = f(i) = max profit if you were robs houses[i...n-1]

        // decide for the ith house

        // option 1 : rob the ith house

        int robIthHouse = nums[i] + dp[i + 2];

        // option 2 : don't rob the ith house

        int donotRobIthHouse = dp[i + 1];

        dp[i] = max(robIthHouse, donotRobIthHouse);


    }

    return dp[0]; // at the 0th index of dp[], we store f(0)

}

int rob(vector<int>& nums) {

    int n = nums.size();

    // return helper(nums, n, 0);

    // vector<int> dp(n + 2, -1);

    // return helperTopDown(nums, n, 0, dp);

    return helperBottomUp(nums, n);

}

int main() {

    vector<int> nums = {100, 50, 400, 200, 100};

    cout << rob(nums) << endl;

    return 0;
}
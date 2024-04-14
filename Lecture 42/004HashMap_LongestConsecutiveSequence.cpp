/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// time : O(n)
	// space: O(n) due to startMap

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap; // to build the startMap, we'll spend O(n)

		for (int i = 0; i < nums.size(); i++) {

			if (startMap.find(nums[i] - 1) == startMap.end()) {

				startMap[nums[i]] = true;

			} else {

				startMap[nums[i]] = false;

			}

			if (startMap.find(nums[i] + 1) != startMap.end()) {

				startMap[nums[i] + 1] = false;

			}

		}

		// for (pair<int, bool> p : startMap) {

		// 	// cout << p.first << " " << boolalpha << p.second << endl;
		// 	cout << p.first << " " << p.second << endl;

		// }

		// cout << endl;

		int maxSoFar = 0; // to track the length of the longest consecutive sequence // time : O(n)

		for (pair<int, bool> p : startMap) {

			int key = p.first;
			bool canStart = p.second;

			if (canStart) {

				int cnt = 0;

				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}

				maxSoFar = max(maxSoFar, cnt);

			}

		}

		return maxSoFar;

	}
};

int main() {


	Solution s;

	vector<int> nums = {1, 4, 12, 3, 11, 13, 14, 15, 16, 2, 5, 8, 9};

	cout << s.longestConsecutive(nums) << endl;

}

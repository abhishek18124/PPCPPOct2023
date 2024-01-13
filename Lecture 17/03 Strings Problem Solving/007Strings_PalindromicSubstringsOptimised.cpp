#include<iostream>
#include<string>

using namespace std;

int countPalindromicSubstrings(const string& s) {

	int n = s.size();

	int cnt = 0; // to track the no. of palindromic substrings in the given string

	// 1. count the no. of odd length palindromic substrings in s

	for (int i = 0; i < n; i++) {

		// cnt the no. of odd length palindromic substrings centred around the ith character

		int j = 0;

		while (i + j <= n - 1 and i - j >= 0 and s[i - j] == s[i + j]) {
			cnt++;
			j++;
		}

	}

	// 2. count the no. of even length palindromic substrings in s

	for (double i = 0.5; i < n; i++) {

		// cnt the no. of odd length palindromic substrings centred around the ith character

		double j = 0.5;

		while (i + j <= n - 1 and i - j >= 0 and s[static_cast<int>(i - j)] == s[static_cast<int>(i + j)]) { // avoid this s[(int)i - j]
			cnt++;
			j++;
		}

	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}
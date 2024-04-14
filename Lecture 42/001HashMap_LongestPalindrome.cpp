#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestPalindrome(string str) {

	unordered_set<char> s;

	int cnt = 0;

	for (char ch : str) {

		if (s.find(ch) == s.end()) {

			s.insert(ch);

		} else {

			cnt += 2;

			s.erase(ch);

		}

	}

	if (s.size() > 0) { // !s.empty()

		cnt++;

	}

	return cnt;


}

int main() {

	string str = "abccccdd";

	cout << longestPalindrome(str) << endl;

	return 0;
}
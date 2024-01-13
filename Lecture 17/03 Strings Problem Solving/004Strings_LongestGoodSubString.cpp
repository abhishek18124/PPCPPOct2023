#include<iostream>
#include<string>

using namespace std;

// time : O(n)

bool isGoodString(const string& str) {

	int n = str.size();

	for (int i = 0; i < n; i++) {

		char ch = str[i];

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}

	}

	// str is a good string

	return true;
}

// time : O(n^3)

int longestGoodSubstr(const string& str) {

	int maxSoFar = 0; // to track the length of the longest good substring we've seen so far

	int n = str.size();

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				maxSoFar = max(maxSoFar, j - i + 1);
			}

		}

	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstr(str) << endl;

	return 0;
}
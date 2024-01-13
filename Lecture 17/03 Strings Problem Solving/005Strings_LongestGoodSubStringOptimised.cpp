#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	int cnt = 0;
	int maxSoFar = 0;

	int n = str.size();

	// time : O(n)

	for (int i = 0; i < n; i++) {

		char ch = str[i];

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			// ch is a vowel
			cnt++;
			maxSoFar = max(maxSoFar, cnt);
		} else {
			// ch is consonant
			cnt = 0;
		}

	}

	cout << maxSoFar << endl;


	return 0;
}
#include<iostream>
#include<queue>

using namespace std;

int main() {

	char ch;
	queue<char> q;

	int freq[26] = {0}; // 0th = freq(a), 1st = freq(b), 2nd = freq(c) ...

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// as of now, ch is non-repeating
			q.push(ch);
		}

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}


	}

	return 0;
}
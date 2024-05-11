#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	// i.e. window that contain k unique characters

	int uniqueCnt = 0; // to keep track of no. of unique characters in the window

	unordered_map<char, int> freqMap; // to store a  mapping  between characters
	// present in a window & their frequencies

	while (j < n) {

		// expand the window
		freqMap[s[j]]++;
		if (freqMap[s[j]] == 1) {
			uniqueCnt++;
		}

		// check for the violation of the window property

		if (uniqueCnt > k) {

			// window property is violated, start shrinking

			while (uniqueCnt > k) {

				freqMap[s[i]]--;
				if (freqMap[s[i]] == 0) {
					uniqueCnt--;
				}
				i++;

			}

		}

		// check for the validity of the window, and update the answer

		if (uniqueCnt == k) {

			// found a valid window from i to j

			max_len = max(max_len, j - i + 1);

		}

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}
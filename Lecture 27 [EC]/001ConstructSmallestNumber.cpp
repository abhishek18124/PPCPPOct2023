#include<iostream>

using namespace std;

bool used[10] = {false}; // to track the digits used in the construction of the
// smallest number corresponding to the given pattern.

void construct(string pattern, string& num, int i) {

	// base case

	if (num.size() == pattern.size() + 1) { // i == pattern.size()
		cout << num << endl;
		return;
	}

	// recursive case

	// decide the next digit

	if (num == "") {

		// decide the 1st digit

		for (int d = 1; d <= 9; d++) {
			num.push_back(d + '0');
			used[d] = true;
			construct(pattern, num, i);
			num.pop_back();
			used[d] = false;
		}

		return;

	}

	int x = num.back() - '0'; // num[num.size()-1]

	if (pattern[i] == 'I') {

		// next digit must be > x

		for (int d = x + 1; d <= 9; d++) {

			// can 'd' be the next digit ?

			if (used[d] == false) {

				// yes, 'd' can be the next digit

				num.push_back(d + '0');
				used[d] = true;
				construct(pattern, num, i + 1);
				num.pop_back();
				used[d] = false;

			}

		}

	} else { // pattern[i] == 'D'

		// next digit must < x

		for (int d = 1; d <= x - 1; d++) {

			// can 'd' be the next digit of 'num' ?

			if (used[d] == false) {

				// yes, 'd' can be the next digit

				num.push_back(d + '0');
				used[d] = true;
				construct(pattern, num, i + 1);
				num.pop_back();
				used[d] = false;

			}

		}

	}
}

int main() {

	string pattern = "DIID";
	string num = "";

	construct(pattern, num, 0);

	return 0;
}
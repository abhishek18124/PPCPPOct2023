#include<iostream>
#include<string>

using namespace std;

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

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;
}
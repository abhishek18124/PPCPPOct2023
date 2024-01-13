#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	for (int l = 1; l <= n; l++) {

		for (int i = 0; i <= n - l; i++) {

			string subString = str.substr(i, l);
			cout << subString << endl;

		}

		cout << endl;

	}

	return 0;
}
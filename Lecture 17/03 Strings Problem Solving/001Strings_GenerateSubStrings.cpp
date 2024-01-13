#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// extrac the substring that starts at the ith index and ends at the jth index

			// for (int k = i; k <= j; k++) {
			// 	cout << str[k];
			// }

			// cout << endl;

			string subString = str.substr(i, j - i + 1);
			cout << subString << endl;

		}

		cout << endl;

	}

	return 0;
}
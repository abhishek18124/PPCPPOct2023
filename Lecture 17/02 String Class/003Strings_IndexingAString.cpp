#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "coding";

	cout << s[0] << endl;
	cout << s[1] << endl;
	cout << s[2] << endl;
	cout << s[3] << endl;
	cout << s[4] << endl;
	cout << s[5] << endl;

	int n = s.length(); // s.size();

	cout << n << endl;

	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}

	cout << endl;

	for (int i = 0; s[i] != '\0'; i++) {
		cout << s[i] << " ";
	}

	cout << endl;

	return 0;
}
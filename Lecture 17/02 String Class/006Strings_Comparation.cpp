#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "axc";
	string s2 = "ab";

	cout << s1.compare(s2) << endl;

	if (s1 > s2) {
		cout << "s1 > s2" << endl;
	} else {
		cout << "s1 < s2" << endl;
	}

	return 0;
}
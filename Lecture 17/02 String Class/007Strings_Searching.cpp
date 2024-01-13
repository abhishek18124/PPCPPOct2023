#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abccdbce";

	cout << s.find("bc") << endl;
	cout << s.rfind("bc") << endl;

	cout << s.find("xyz") << endl;
	cout << string::npos << endl;

	if (s.find("xyz") == string::npos) {
		cout << "xyz is not present" << endl;
	}

	return 0;
}
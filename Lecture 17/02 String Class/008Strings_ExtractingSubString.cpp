#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";

	cout << s.substr(2, 3) << endl;
	cout << s.substr(2) << endl;
	// cout << s.substr(2, 10) << endl; // avoid this
	// cout << s.substr(10) << endl; // error
	// cout << s.substr(10, 0) << endl; // error

	return 0;
}
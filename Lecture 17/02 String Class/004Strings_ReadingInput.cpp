#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string str;
	cout << "enter a string : ";
	// cin >> str;
	// getline(cin, str);
	// getline(cin >> ws, str);
	getline(cin >> ws, str, '$');

	cout << "you've entered str = " << str << endl;

	return 0;
}
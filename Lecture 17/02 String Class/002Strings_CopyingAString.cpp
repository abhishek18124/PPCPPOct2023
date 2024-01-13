#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "wow";
	string s2 = s1; // copy constructor
	cout << s2 << endl;

	string s3;
	s3 = s1; // copy assignment operator
	cout << s3 << endl;

	return 0;
}
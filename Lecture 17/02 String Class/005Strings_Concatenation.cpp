#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "xyz";

	// s1.append(s2);

	// cout << s1 << endl;
	// cout << s2 << endl;

	cout << s1 + s2 << endl;
	cout << s1 << endl;
	cout << s2 << endl;

	string s = "abc";
	cout << s << endl;

	s.push_back('d');
	cout << s << endl;

	s.pop_back();
	s.pop_back();
	cout << s << endl;

	cout << s[0] << " " << s.front() << endl;
	cout << s[s.size() - 1] << " " << s.back() << endl;

	return 0;
}
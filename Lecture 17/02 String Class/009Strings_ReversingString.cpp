#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abcdef";

	// reverse(s.begin(), s.end());
	// reverse(s.begin() + 2, s.begin() + 5); // [2, 5)
	reverse(s.begin() + 2, s.end() - 1);
	cout << s << endl;

	return 0;
}
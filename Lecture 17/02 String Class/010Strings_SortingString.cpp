#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "xabcw";

	// sort(s.begin(), s.end());

	// sort(s.rbegin(), s.rend()); // decreasing order

	sort(s.begin(), s.end(), greater<char>());

	cout << s << endl;

	return 0;
}
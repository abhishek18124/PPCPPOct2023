#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {

	// base case

	if (str.empty()) { // str == "" // n == 0
		return 0;
	}

	// recursive case

	string subString = str.substr(0, n - 1);
	int integerFromMyFriend = stringToInteger(subString, n - 1);

	// return integerFromMyFriend * 10 + (str[n - 1] - '0');

	int lastDigit = str[n - 1] - '0'; // str.back() - '0'
	return integerFromMyFriend * 10 + lastDigit;

}

int main() {

	string str = "123";
	int n = str.size();

	cout << stringToInteger(str, n) << endl;

	return 0;
}
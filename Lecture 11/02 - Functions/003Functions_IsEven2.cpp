#include<iostream>

using namespace std;

bool isEven(int n) {

	return n % 2 == 0;

}

int main() {

	bool ans = isEven(4);

	cout << ans << endl;

	cout << isEven(5) << endl;

	if (isEven(7)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}


	if (isEven(6)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(8) ? cout << "even" << endl : cout << "odd" << endl;

	isEven(9) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}
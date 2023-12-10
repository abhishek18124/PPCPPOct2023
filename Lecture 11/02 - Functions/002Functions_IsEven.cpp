#include<iostream>

using namespace std;

void isEven(int n) {

	// n is declarared within the scope of isEven and the argument value passed
	// during function call is copied into it.

	if (n % 2 == 0) {

		cout << n << " is even" << endl;

	} else {

		cout << n << " is odd" << endl;

	}

}

int main() {


	isEven(2);

	isEven(4);

	isEven(5);

	return 0;
}
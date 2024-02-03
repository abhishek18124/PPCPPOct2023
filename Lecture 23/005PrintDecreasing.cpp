#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {
		return; // mandatory
	}

	// recursive case

	cout << n << " ";

	f(n - 1);

	return; // optional

}

int main() {

	int n = 5;

	f(n);

	return 0;
}
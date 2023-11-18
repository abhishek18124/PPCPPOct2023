#include<iostream>

using namespace std;

int main() {

	const int x = 10;

	cout << x << endl;

	cout << x + 1 << endl;

	// x++; // x is a const(read-only) variable, it cannot be modified

	return 0;
}
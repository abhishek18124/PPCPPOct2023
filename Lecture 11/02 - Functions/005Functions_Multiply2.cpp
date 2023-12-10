#include<iostream>

using namespace std;

int multiply(int a, int b) {

	cout << "a = " << a << " b = " << b << endl;

	a++;
	b++;

	cout << "a = " << a << " b = " << b << endl;

	return a * b;


}

int main() {

	int a = 2;
	int b = 3;

	cout << "inside main(), before multiply() a = " << a << " b = " << b << endl;

	cout << multiply(a, b) << endl;

	cout << "inside main(), after multiply() a = " << a << " b = " << b << endl;

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int* ptr = new int;

	*ptr = 50;

	cout << *ptr << endl;

	delete ptr; // to avoid memory leak

	ptr = new int;

	*ptr = 75;

	cout << *ptr << endl;

	delete ptr; // to avoid memory leak

	return 0;
}
#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	// cout << (void*)&greet << endl;
	// cout << (void*)&add << endl;
	// cout << (void*)&ascending << endl;

	cout << (void*)greet << endl;
	cout << (void*)add << endl;
	cout << (void*)ascending << endl;

	// void (*gptr)() = &greet;
	// int (*aptr)(int, int) = &add;
	// bool (*ascptr)(int, int) = &ascending;

	void (*gptr)() = greet;
	int (*aptr)(int, int) = add;
	bool (*ascptr)(int, int) = ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl;

	(*gptr)();
	(*greet)();
	greet();
	gptr();

	cout << (*aptr)(2, 3) << endl;
	cout << (*add)(2, 3) << endl;
	cout << add(2, 3) << endl;
	cout << aptr(2, 3) << endl;

	cout << (*ascptr)(4, 5) << endl;
	cout << (*ascending)(4, 5) << endl;
	cout << ascending(4, 5) << endl;
	cout << ascptr(4, 5) << endl;

	return 0;
}
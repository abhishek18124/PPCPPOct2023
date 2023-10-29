#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << x << endl;

	{
		int y = 20;

		cout << x << " " << y << endl;

	}

	// cout << x << " " << y << endl; // error : y is out of scope

	return 0;
}
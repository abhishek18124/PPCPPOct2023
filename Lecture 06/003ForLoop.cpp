#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	cout << i << " ";
	// }

	// cout << i << endl; // error

	// int i = 0;

	// for (; i < n; i++) {
	// 	cout << i << " ";
	// }

	int i;

	for (i = 0; i < n; i++) {
		cout << i << " ";
	}

	cout << endl << "outside loop i = " << i << endl; // works

	cout << endl;

	return 0;
}
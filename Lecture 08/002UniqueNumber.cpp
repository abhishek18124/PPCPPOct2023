#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int ans = 0; // to store the unique number

	for (int i = 0; i < n; i++) {

		int data;
		cin >> data;

		ans = ans ^ data;

	}

	cout << ans << endl;

	return 0;
}
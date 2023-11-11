#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << "  ";
		}

		// followed by i numbers in the increasing orders starting with i

		int num = i;

		for (int j = 1; j <= i; j++) {
			cout << num << " ";
			num++;
		}

		// followed by i-1 more numbers in the decreasing order starting with 2i-2

		num = num - 2;

		for (int j = 1; j <= i - 1; j++) {
			cout << num << " ";
			num--;
		}

		cout << endl;

	}

	return 0;
}
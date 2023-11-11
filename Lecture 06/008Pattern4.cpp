#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;

	while (i <= n) {

		int j = 1;

		int num;

		if (i % 2 == 0) {
			// i is even
			num = 0;
		} else {
			num = 1;
		}

		// int num = (i % 2 == 0) ? 0 : 1;

		while (j <= i) {

			cout << num << " ";

			num = !num;

			// if(num == 0) {
			// 	num = 1;
			// } else {
			// 	num = 0;
			// }

			// num = 1 - num;

			j++;

		}

		i++;

		cout << endl;

	}

	return 0;
}
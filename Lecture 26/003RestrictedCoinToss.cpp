// n <= 10

#include<iostream>

using namespace std;

void f(int n, char out[], int i) {

	// base case

	if (i == n) {
		out[i] = '\0';

		// check the validity of the out[]

		for (int i = 1; out[i] != '\0'; i++) {
			if (out[i] == 'H' and out[i - 1] == 'H') {
				// out[] is not valid;
				return;
			}
		}

		cout << out << endl;

		return;
	}

	// recursive case

	// take a sequence of n-i decisions for coins i to n-1

	// decide for the ith coin

	// option 1 : ith coin shows head

	out[i] = 'H';
	f(n, out, i + 1);

	// option 2 : ith coin shows tail

	out[i] = 'T';
	f(n, out, i + 1);

}

int main() {

	int n = 3;

	char out[10];

	f(n, out, 0);

	return 0;
}
// n <= 10

#include<iostream>

using namespace std;

void f(int n, string& out, int i) {

	// base case

	if (i == n) {
		cout << out << endl;
		return;
	}

	// recursive case

	// take a sequence of n-i decisions for coins i to n-1

	// decide for the ith coin

	// option 1 : ith coin shows head

	if (i == 0 || out[i - 1] != 'H') {
		out.push_back('H');
		f(n, out, i + 1);
		out.pop_back(); // backtracking
	}

	// option 2 : ith coin shows tail

	out.push_back('T');
	f(n, out, i + 1);
	out.pop_back();

}

int main() {

	int n = 3;

	string out;

	f(n, out, 0);

	return 0;
}
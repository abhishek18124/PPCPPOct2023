#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// compute x*0
		return 0;
	}

	// recursive case

	// compute x*y i.e. add x y times

	// 1. ask your friend to compute x*(y-1)

	int A = f(x, y - 1);
	return x + A;

}

int main() {

	int x = 2;
	int y = 7;

	cout << f(x, y) << endl;

	return 0;
}
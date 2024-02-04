#include<iostream>

using namespace std;

void f(int n, char src, char dst, char hlp) {

	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// 1. recursively, move n-1 disks from A(src) to B(helper) using C(destination)
	f(n - 1, src, hlp, dst);

	// 2. move the largest disk from A(src) to C(destination)
	cout << "move disk from " << src << " to " << dst << endl;

	// 3. recursively, move n-1 disks from B(helper) to C(destination) using A(src)
	f(n - 1, hlp, dst, src);

}

int main() {

	int n = 4;

	f(n, 'A', 'C', 'B');

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int n = 169;
	int m = 10;

	int i = 3;
	int j = 6;

	// 1. clear bits i to j in n

	int mask1 = (-1 << (j + 1));
	int mask2 = ~(-1 << i);

	int mask = mask1 | mask2;

	n = n & mask;

	int mask3 = m << i;

	cout << (n | mask3) << endl;

	return 0;
}
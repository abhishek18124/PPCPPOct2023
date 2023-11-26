#include<iostream>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};

	for (int i = 0; i < 5; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	int B[] = {100, 200, 300};

	cout << sizeof(B) << "B" << endl;

	int n = sizeof(B) / sizeof(int);

	cout <<  n << endl;

	for (int i = 0; i < n; i++) {
		cout << B[i] << " ";
	}

	cout << endl;

	int C[10] = {11, 12, 13, 14};

	for (int i = 0; i < 10; i++) {

		cout << C[i] << " ";

	}

	cout << endl;

	// int D[5] = {21, 22, 23, 24, 25, 26}; // error

	int E[5] = {0};

	for (int i = 0 ; i < 5; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[5] = {};

	for (int i = 0; i < 5; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	int G[5];

	memset(G, 0, sizeof(G));

	for (int i = 0; i < 5; i++) {
		cout << G[i] << " ";
	}

	cout << endl;


	return 0;
}
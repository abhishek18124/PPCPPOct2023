// strlen <= 100

#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the no. of strings : ";
	cin >> n;

	cin.ignore(); // to consume the '\n' after n

	// cin.get();

	char inp[101]; // based on the constraints
	cin.getline(inp, 101, '\n');

	char lsf[101];
	strcpy(lsf, inp);

	for (int i = 1; i <= n - 1; i++) {

		cin.getline(inp, 101, '\n');
		if (strcmp(inp, lsf) > 0) {
			strcpy(lsf, inp);
		}

	}

	cout << lsf << endl;

	return 0;
}

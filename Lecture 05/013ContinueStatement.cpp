#include<iostream>
#include<climits>

using namespace std;

int main() {

	int i = 0;

	while (i < 5) {
		i = i + 1;
		if (i == 2) {
			continue;
		}
		cout << i << " ";
	}

	// int i = 1;
	// while (i <= 5) {

	// 	cout << ".";

	// 	if (i == 2) continue;

	// 	cout << i << " ";
	// 	i = i + 1;

	// }

	return 0;
}
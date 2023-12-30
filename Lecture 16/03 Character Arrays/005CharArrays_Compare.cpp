#include<iostream>
#include<cstring>

using namespace std;

// length of str1 = m
// length of str2 = n

// min(m, n) steps

int compareString(char str1[], char str2[]) {

	int i = 0; // to iterate over str1[]
	int j = 0; // to iterate over str2[]

	while (str1[i] != '\0' and str2[j] != '\0') {

		if (str1[i] > str2[j]) {

			// str1 > str2

			return 1;

		}

		if (str1[i] < str2[j]) {

			// str1 < str2

			return -1;

		}

		i++;
		j++;

	}


	if (str1[i] == '\0' and str2[j] == '\0') {

		return 0;

	}

	if (str1[i] == '\0' and str2[j] != '\0') {

		// length of str1 < length of str2 => str1 < str2

		return -1;


	}

	// length of str1 > length of str2 => str1 > str2

	return 1;

}

int main() {

	char str1[] = "zzzz";
	char str2[] = "zazz";

	// int out = compareString(str1, str2);

	int out = strcmp(str1, str2);

	if (out == 0) {

		cout << str1 << " is equal to " << str2 << endl;

	} else if (out > 0) { // out == 1

		cout << str1 << " > " << str2 << endl;

	} else {

		cout << str1 << " < " << str2 << endl;

	}

	return 0;
}
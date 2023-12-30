#include<iostream>
#include<cstring>

using namespace std;

// steps is proportional to length of str2[]

void copyString(char str1[], char str2[]) {

	int i = 0; // to iterate over str1[]
	int j = 0; // to iterate over str2[]

	while (str2[j] != '\0') {

		str1[i] = str2[j];
		i++;
		j++;

	}

	str1[i] = '\0';

}

int main() {

	char str1[100] = "abcd";
	char str2[] = "xy";

	cout << "Before copy : " << str1 << endl;

	// copyString(str1, str2);

	strcpy(str1, str2);

	cout << "After copy : " << str1 << endl;

	return 0;
}
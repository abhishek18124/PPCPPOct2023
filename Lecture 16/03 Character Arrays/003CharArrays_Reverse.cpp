#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverseString(char str[]) {

	int i = 0;
	int j = strlen(str) - 1;

	while (i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}

}

int main() {

	char str[] = "coding";

	cout << "Original string : " << str << endl;

	// reverseString(str);

	int n = strlen(str);

	reverse(str, str + n);

	cout << "Reversed  string after 1st reverse : " << str << endl;


	return 0;
}
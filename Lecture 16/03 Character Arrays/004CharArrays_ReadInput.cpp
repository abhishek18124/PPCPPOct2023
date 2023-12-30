// n <= 100

#include<iostream>

using namespace std;

void readString(char str[], char dlim = '\n') {

	char ch;
	int i = 0;

	while (true) {

		ch = cin.get();
		if (ch == dlim) {
			break;
		}

		str[i] = ch;
		i++;

	}

	str[i] = '\0';

}

int main() {

	char str[101];

	cout << "enter a string : ";

	// cin >> str;

	// readString(str, 'l');

	// cin.getline(str, 101, '\n'); // '\n' is by default the delimiting character

	// cin.getline(str, 5, '\n');

	// cin.getline(str, 101, '$');

	cin.getline(str, 101, 'l');

	cout << "You've entered : " << str << endl;

	return 0;
}
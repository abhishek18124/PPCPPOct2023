#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = "a$bc.de$.f.ghi";
	char dlim[] = ".$";

	char* token = strtok(str, dlim);

	while (token != NULL) {

		cout << token << endl;
		token = strtok(NULL, dlim);

	}

	return 0;
}
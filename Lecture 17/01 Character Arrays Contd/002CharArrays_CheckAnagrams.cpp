#include<iostream>

using namespace std;

bool isAnagram(char s1[], char s2[]) {

	int f1[26] = {};
	// int f1[26] = {0};
	// memset(f1, 0, sizeof(f1));

	for (int i = 0; s1[i] != '\0'; i++) {

		char ch = s1[i];
		int idx = ch - 'a';
		f1[idx]++;

	}

	for (int i = 0; i < 26; i++) {
		cout << f1[i] << " ";
	}

	cout << endl;

	int f2[26] = {};

	for (int i = 0; s2[i] != '\0'; i++) {
		f2[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << f2[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 26; i++) {

		if (f1[i] != f2[i]) {

			return false;

		}

	}

	// s1[] and s2[] are anagrams

	return true;

}

int main() {

	char s1[] = "aabbbcc";
	char s2[] = "aaabbcc";

	isAnagram(s1, s2) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
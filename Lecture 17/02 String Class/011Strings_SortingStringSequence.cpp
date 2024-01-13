#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want 'a' to be ordered before 'b' otherwise return false

bool compartor(string a, string b) {

	// if (a.size() < b.size()) {
	// 	return true;
	// }

	// return false;

	return a.size() < b.size();

}

int main() {

	string arr[] = {"xyz", "zz", "abcde", "w", "mnop"};
	int n = 5;

	// sort(arr, arr + n); // arr[] is sorted in the lex. inc. order

	// sort(arr, arr + n, greater<string>()); // arr[] is sorted in the lex. dec. order

	sort(arr, arr + n, compartor);

	for (int i = 0; i < n; i++) {
		cout << arr[i]  << " ";
	}

	cout << endl;

	return 0;
}
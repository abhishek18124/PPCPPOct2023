#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// time : O(n)
// space: O(n) if all the elements are distinct

bool checkDuplicate1(vector<int> v) {

	unordered_map<int, int> freqMap;

	for (int i = 0; i < v.size(); i++) {

		freqMap[v[i]]++;
		// if (freqMap[v[i]] > 1) {
		// 	return true;
		// }

	}

	for (pair<int, int> p : freqMap) {
		cout << p.first << " " << p.second << endl;
	}

	for (pair<int, int> p : freqMap) {
		if (p.second > 1) {
			// p.first is a duplicate
			return true;
		}
	}

	return false;

}

// time : O(n)
// space: O(n)

bool checkDuplicate2(vector<int> v) {

	unordered_set<int> s;

	for (int i = 0; i < v.size(); i++) {

		if (s.find(v[i]) == s.end()) {

			s.insert(v[i]);

		} else {

			// v[i] is already present in the set i.e. you've found duplicate

			return true;

		}

	}

	// no duplicates found

	return false;

}

int main() {

	vector<int> v = {1, 2, 3};

	checkDuplicate1(v) ? cout << "true" << endl : cout << "false" << endl;

	checkDuplicate2(v) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
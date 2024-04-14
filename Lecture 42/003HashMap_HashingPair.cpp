#include<iostream>
#include<unordered_map>

using namespace std;

class PairHash {

public :

	size_t operator()(pair<string, int> p) const {

		string name = p.first;
		int age = p.second;

		return hash<string>()(name) ^ hash<int>()(age);

	}

};

int main() {

	unordered_map<pair<string, int>, double, PairHash> ratingMap;

	ratingMap[ {"rudraksh", 20} ] = 4.5; // ratingMap[make_pair("rudraksh", 20)] = 4.5;
	ratingMap[ {"anshita", 18} ] = 4.7;
	ratingMap[ {"vansh", 20} ] = 1.2;

	for (pair<pair<string, int>, double> p : ratingMap) {

		pair<string, int> c = p.first;
		double r = p.second;

		cout << c.first << " " << c.second << " : " << r << endl;

	}

	cout << endl;

	ratingMap[ {"rudraksh", 20} ] = 4.9;

	for (pair<pair<string, int>, double> p : ratingMap) {

		pair<string, int> c = p.first;
		double r = p.second;

		cout << c.first << " " << c.second << " : " << r << endl;

	}
	return 0;
}
#include<iostream>
#include<unordered_map>

using namespace std;

class customer {

public :

	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(customer other) const  {
		return this->name == other.name and this->age == other.age;
	}

};

// customer c("...")
// customer d("...")

// if(c == d) { // c.operator==(d) // c is this, d is other

// }

class customerHash {

public:

	size_t operator()(customer c) const {

		// string name = c.name;
		// int age = c.age;

		// hash<string> stringHash;
		// hash<int> integerHash;

		// return stringHash(name) ^ integerHash(age);

		return hash<string>()(c.name) ^ hash<int>()(c.age);

	}

};

int main() {

	unordered_map<customer, double, customerHash> ratingMap;

	ratingMap[customer("rudraksh", 20)] = 4.5;
	ratingMap[customer("anshita", 18)] = 4.7;
	ratingMap[customer("vansh", 20)] = 1.2;
	ratingMap[customer("abhishek", 29)] = 5;
	ratingMap[customer("manan", 19)] = 4.2;

	for (pair<customer, double> p : ratingMap) {

		customer c = p.first;
		double r = p.second;

		cout << c.name << " " << c.age << " : " << r << endl;

	}

	cout << endl;

	ratingMap[customer("rudraksh", 20)] = 4.9;

	for (pair<customer, double> p : ratingMap) {

		customer c = p.first;
		double r = p.second;

		cout << c.name << " " << c.age << " : " << r << endl;

	}

	return 0;
}
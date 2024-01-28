#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool ageComparator(customer a, customer b) {

	if (a.age < b.age) {
		// a should come before b if you are sorting inc. order
		return true;
	}

	return false;

}


bool creditCompartor(customer a, customer b) {

	if (a.credits > b.credits) {
		// a should come before b if you are sorting dec. order based on credits
		return true;
	}

	return false;

}

class ageFunctor {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// a should come before b if you are sorting inc. order
			return true;
		}

		return false;
	}

};


class creditsFunctor {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(customer a, customer b) {
		if (a.credits > b.credits) {
			// a should come before b if you are sorting dec. order based on credits
			return true;
		}

		return false;
	}

};

int main() {

	vector<customer> v;

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	sort(v.begin(), v.end(), ageComparator);

	// sort(v.begin(), v.end(), ageFunctor());

	// for (customer c : v) {
	// 	cout << c.name << " " << c.age << endl;
	// }

	// sort(v.begin(), v.end(), creditCompartor);

	sort(v.begin(), v.end(), creditsFunctor());

	for (customer c : v) {
		cout << c.name << " " << c.credits << endl;
	}

	return 0;
}
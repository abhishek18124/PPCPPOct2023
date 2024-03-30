/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;
	double balance;

	customer(string name, int age, double balance) {
		this->name = name;
		this->age = age;
		this->balance = balance;
	}

};

// class balanceComparator {

// public:

// 	// return true if you want a to be ordered before b otherwise return false

// 	bool operator()(customer a, customer b) {

// 		if (a.balance > b.balance) {

// 			// I want a to be ordered before b

// 			return true;

// 		}

// 		return false;

// 	}

// };


class balanceComparator {

public:

	// return false if you want a to be given higher priority than b otherwise return true

	bool operator()(customer a, customer b) {

		if (a.balance > b.balance) {

			// I want a to be given more priority than b

			return false;

		}

		return true;

	}

};

int main() {

	priority_queue<customer, vector<customer>, balanceComparator> m; // build a maxHeap of customers based on their balance

	m.push(customer("Aman", 19, 1000));
	m.push(customer("Rudraskh", 20, 1500));
	m.push(customer("Anish", 18, 700));
	m.push(customer("Jiya", 21, 300));
	m.push(customer("Joshita", 17, 600));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << " " << c.balance << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}
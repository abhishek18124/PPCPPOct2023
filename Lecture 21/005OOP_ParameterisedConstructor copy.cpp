#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the param. const. of the customer class\n";
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	customer() {
		cout << "\ninside the default constructor of the customer class\n";
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl;
	}
};



int main() {

	customer c("Ramanujan", 32, 'M', 1729);

	c.print();

	customer c1;

	return 0;
}
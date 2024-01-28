#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

void printByValue(customer c) {

	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

}

void printByRef(customer& ref) {

	cout << "name = " << ref.name << endl;
	cout << "age = " << ref.age << endl;
	cout << "gender = " << ref.gender << endl;
	cout << "credits = " << ref.credits << endl << endl;

}


void printByConstRef(const customer& ref) {

	cout << "name = " << ref.name << endl;
	cout << "age = " << ref.age << endl;
	cout << "gender = " << ref.gender << endl;
	cout << "credits = " << ref.credits << endl << endl;

}

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	// printByValue(c1);
	// printByRef(c1);
	printByConstRef(c1);

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	// printByValue(c2);
	// printByRef(c2);
	printByConstRef(c2);


	return 0;
}
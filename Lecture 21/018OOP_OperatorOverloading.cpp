#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	// bool operator>(customer c) {
	// 	return age > c.age;
	// }

	bool operator>(const customer& c) { // c is ref to c2
		return age > c.age;
	}

	bool operator==(const customer& c) {  // c is ref to c2
		return credits == c.credits;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

};

int operator+(const customer& c1, const customer& c2) {
	return c1.credits + c2.credits;
}

string operator*(string s, int x) {
	string out = "";
	while (x--) {
		out += s;
	}
	return out;
}

int main() {

	customer c1("Ramanujan", 32, 'M', 1729);
	customer c2("Aryabhata", 74, 'M', 500);

	c1 > c2 ? cout << "c1.age > c2.age" << endl : cout << "c1.age < c2.age" << endl;
	// c1.operator > (c2) ? cout << "c1.age > c2.age" << endl : cout << "c1.age < c2.age" << endl;

	c1 == c2 ? cout << "c1.credits are equal to c2.credits" << endl : cout << "c1.credits are not equal to c2.credits" << endl;
	// c1.operator==(c2)

	cout << c1 + c2 << endl; // operator+(c1, c2)

	string s1 = "a";
	int x = 5;

	cout << s1*x << endl; // operator*(s1, x)

	return 0;

}
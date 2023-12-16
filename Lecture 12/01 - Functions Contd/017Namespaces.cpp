#include<iostream>

using namespace std;

namespace one {

int f(int a, int b) {
	return a + b;
}

}

namespace two {

int f(int a, int b) {
	return a - b;
}

}

int main() {

	cout << one::f(5, 4) << endl;
	cout << two::f(5, 4) << endl;

	std::cout << "hello" << std::endl;

	return 0;
}
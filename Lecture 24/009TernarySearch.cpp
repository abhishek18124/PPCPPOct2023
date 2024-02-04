#include<iostream>
#include<iomanip>

using namespace std;

int f(int x) {
	return -x * x + 100 * x; // -x^2 + 100x is a unimodal function
}

double findPeak(double s, double e) {

	while (e - s > 1e-6) {

		double m1 = s + (e - s) / 3;
		double m2 = e - (e - s) / 3;

		cout << s << " " << e << endl;

		if (f(m1) > f(m2)) {
			// move towards the left of m2 i.e. reduce the search space from [s, e] to [s, m2]
			e = m2;
		} else {
			// move towards the right of m1 i.e. reduce the search space from [s, e] to [m1, e]
			s = m1;
		}

	}

	// return f(s); // f(e)

	return f((s + e) / 2);

}

int main() {

	cout << setprecision(20) << fixed;

	double s = 0;
	double e = 100;

	cout << findPeak(s, e) << endl;

	return 0;
}
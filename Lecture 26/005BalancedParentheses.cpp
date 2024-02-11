// n <= 8

#include<iostream>

using namespace std;

vector<string> v;

void f(int n, string& out, int i, int openCnt, int closeCnt) {

	// base case

	if (i == 2 * n) {
		v.push_back(out);
		return;
	}

	// recursive case

	// take decisions for the remaining 2n-i positions from i to 2n-1

	// decide the ith position

	// option 1 : use '('
	if (openCnt < n) {
		out.push_back('(');
		f(n, out, i + 1, openCnt + 1, closeCnt);
		out.pop_back(); // backtracking
	}

	// option 2 : use ')'
	if (closeCnt < openCnt) {
		out.push_back(')');
		f(n, out, i + 1, openCnt, closeCnt + 1);
		out.pop_back();
	}

}

int main() {

	int n = 3;

	string out;

	f(n, out, 0, 0, 0);

	for (string str : v) {
		cout << str << endl;
	}

	return 0;
}
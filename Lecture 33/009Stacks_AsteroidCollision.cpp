#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {
		if (ast < 0 and !s.empty() and s.top() > 0) {
			// 'ast' will collide intially s.top()
			bool flag = true; // assume 'ast' will destroy all the +ve wgt asteroid on the top of the stack
			while (!s.empty() and s.top() > 0) {
				// 'ast' will collide with s.top()
				if (abs(ast) > s.top()) {
					// s.top() will be destroyed
					s.pop();
				} else if (abs(ast) < s.top()) {
					// ast will be destroyed
					flag = false;
					break;
				} else { // abs(ast) is equal to s.top()
					// both ast and s.top() will be destroyed
					flag = false;
					s.pop();
					break;
				}
			}

			if (flag == true) {
				// 'ast' has destroyed all the +ve weight asteroid on the top of the stack and still survived
				s.push(ast);
			}

		} else {

			s.push(ast);

		}
	}

	vector<int> out;

	while (!s.empty()) {
		out.push_back(s.top());
		s.pop();
	}

	reverse(out.begin(), out.end());

	return out;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> output = asteroidCollision(asteroids);

	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}

	cout << endl;

	return 0;
}
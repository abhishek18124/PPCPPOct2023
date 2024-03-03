#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int data) {

	// base case

	if (s.empty()) { // or s.size() == 0
		s.push(data);
		return;
	}

	// recursive case

	int temp = s.top();
	s.pop();

	insertAtBottom(s, data);

	s.push(temp);

}

void reverse(stack<int>& s) {

	// base case

	if (s.empty()) {
		return;
	}

	// recursive case

	int temp = s.top();
	s.pop();

	reverse(s);

	insertAtBottom(s, temp);

}

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	reverse(s);

	print(s);

	return 0;
}
#include<iostream>
#include<stack>

using namespace std;

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack;

public :

	void push(int data) {
		main_stack.push(data);
		if (min_stack.empty() || data <= min_stack.top()) {
			min_stack.push(data);
		}
	}

	void pop() {
		if (empty()) {
			// custom stack is empty
			return;
		}
		int temp = main_stack.top();
		main_stack.pop();
		if (min_stack.top() == temp) {
			min_stack.pop();
		}
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.empty(); // or min_stack.empty();
	}

	int top() { // assume stack is non-empty
		return main_stack.top();
	}

	// although the time complexity of getMin() is O(1) but we are maintaining a
	// min_stack which in the worst case (inp. is in dec. order) will take O(n) space

	// try to implement getMin() in O(1) time and O(1) space ?

	int getMin() { // assume stack is non-empty
		return min_stack.top();
	}

};

int main() {

	custom_stack cs;

	cs.push(10);
	cs.push(0);
	cs.push(0);

	cout << "minTop : " << cs.getMin() << endl;

	cs.pop();

	cout << "minTop : " << cs.getMin() << endl;


	// cs.push(10);
	// cs.push(0);
	// cs.push(20);

	// cout << "top : " << cs.top() << endl;
	// cout << "minTop : " << cs.getMin() << endl;

	// cs.push(-5);
	// cs.push(30);

	// cout << "top : " << cs.top() << endl;
	// cout << "minTop : " << cs.getMin() << endl;

	// cs.pop();

	// cout << "top : " << cs.top() << endl;
	// cout << "minTop : " << cs.getMin() << endl;

	// cs.pop();

	// cout << "top : " << cs.top() << endl;
	// cout << "minTop : " << cs.getMin() << endl;

	return 0;
}

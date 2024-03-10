#include<iostream>
#include<list>

using namespace std;

template <typename T>
class queue {
	list<T> dll;

public:

	// head = front of queue
	// tail = read of queue

	void push(T val) {

		// insert at tail

		dll.push_back(val);

	}

	void pop() {

		// delete at head

		if (empty()) {
			return;
		}

		dll.pop_front();

	}

	T front() {

		// head->val

		return dll.front();

	}

	int size() {

		return dll.size();

	}

	bool empty() {

		// head == NULL

		return dll.empty();

	}

};

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl;
	cout << "empty : " << q.empty() << endl;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();
	q.empty() ? cout << "Queue is empty!" << endl :
	                 cout << "Queue is not empty!" << endl;

	return 0;
}
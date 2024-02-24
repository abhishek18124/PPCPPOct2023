#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}


ListNode* getNode(ListNode* head, int j) {

	// it will return the address of the node at the jth index

	int k = 1;

	while (head != NULL and k <= j) {
		head = head->next;
		k++;
	}

	return head;

}

// time : O(n)

void deleteAtIndex(ListNode*& head, int i) {

	if (i == 0) {
		deleteAtHead(head);
		return;
	}

	// i >= 1

	ListNode* cur = getNode(head, i);
	if (cur == NULL) {
		// i >= n i.e. i is an invalid index
		return;
	}

	// cur != NULL
	ListNode* prev = getNode(head, i - 1);

	// following check is not required since prev will 100% exist

	// if (prev == NULL) {
	// 	return;
	// }

	prev->next = cur->next;
	delete cur;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head, 100);

	printLinkedList(head);

	return 0;
}
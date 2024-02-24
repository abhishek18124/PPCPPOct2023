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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

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

void insertAtIndex(ListNode*& head, int val, int i) {

	if (i == 0) {
		insertAtHead(head, val);
		return;
	}

	ListNode* n = new ListNode(val);
	ListNode* prev = getNode(head, i - 1); // linear time
	if (prev == NULL) {
		// i exceed length of the LinkedList
		return;
	}
	n->next = prev->next;
	prev->next = n;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	insertAtIndex(head, 100, 5);

	printLinkedList(head);

	return 0;
}
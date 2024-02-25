#include<iostream>

using namespace std;

class ListNode {
public:

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

ListNode* computeMidPoint(ListNode* head) {

	if (head == NULL) {
		// LinkedList is empty
		return NULL;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next != NULL) {

		slow = slow->next;
		fast = fast->next->next;

	}

	return slow;

}

ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp = dummy;

	while (head1 != NULL and head2 != NULL) {

		if (head1->val < head2->val) {

			temp->next = head1;
			head1 = head1->next;
			temp = temp->next;

		} else {

			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;

		}

	}

	if (head1 != NULL) {
		temp->next = head1;
	}

	if (head2 != NULL) {
		temp->next = head2;
	}

	return dummy->next;

}

// time : t(n) = 2t(n/2) + n + n/2 ~ O(nlogn)
// space : O(logn) due to function call stack


ListNode* mergeSort(ListNode* head) {

	// if (head == NULL) {
	// 	// LinkedList is empty
	// 	return head;
	// }

	// if (head->next == NULL) {
	// 	// LinkedList has one node
	// 	return head;
	// }

	// base case

	if (head == NULL || head->next == NULL) {
		return head;
	}

	// recursive case

	// 1. divide the LinkedList around the midPoint
	ListNode* midPoint = computeMidPoint(head);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. recursively sort the two sublists
	head = mergeSort(head);
	head2 = mergeSort(head2);

	// 3. merge the two sorted sublists
	return mergeSorttedLinkedList(head, head2);

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}
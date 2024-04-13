/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

public :

	int K;
	int V;
	node* next;

	node(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the pointer to the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(node* head) {

		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap

		node* temp = head;
		while (temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer

		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}


	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity

		node** oldT = T;
		int oldN = N;

		// 2. create a hashMap with double capacity

		N = N * 2;
		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
		M = 0;

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap
		for (int i = 0; i < oldN; i++) {
			transfer(oldT[i]);
		}

		// 4. release the memory allocated to the old hashMap
		delete [] oldT;

	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0;
		this->L = L;

		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. create a node with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index

		node* n = new node(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created node

		n->next = T[hashIdx];
		T[hashIdx] = n;

		M++;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold

		double LF = (double)M / N;
		if (LF > L) {
			cout << "LF = " << LF << endl;
			rehash();
		}

	}

	node* find(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. search for the node with the given key in the  linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				break;
			}
			temp = temp->next;
		}

		return temp;


	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx  = hashFn(K);

		// 2. delete the node with the given key from the linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];

		if (temp == NULL) {

			// given K doesn't exist

			return;

		}

		if (temp->K == K) {

			// delete at head

			T[hashIdx] = temp->next;
			delete temp;
			M--;

			return;

		}

		node* prev = NULL;

		while (temp != NULL) {

			if (temp->K == K) {

				// delete temp

				prev->next = temp->next;
				delete temp;
				M--;

				break;

			}

			prev = temp;
			temp = temp->next;

		}

	}

	void printLinkedList(node* head) {
		while (head) { // head != NULL
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}

	int& operator[](int K) {

		node* temp = find(K);

		if (temp == NULL) {
			// K is not present

			int val; // garbage
			insert(K, val);
			temp = find(K);

		}

		return temp->V;

	}
};

int main() {

	HashMap hm;

	hm.insert(3, 9);
	hm.insert(8, 64);
	hm.insert(6, 36);

	hm.printHashMap();

	int key = 3;

	node* temp = hm.find(key);

	if (temp != NULL) {

		// given key exists

		cout << temp->V << endl;

	} else {

		// given key doesn't exist

		cout << key << " not found" << endl;

	}

	hm.insert(11, 121);

	hm.printHashMap();

	hm.insert(7, 49);
	hm.insert(2, 4);

	hm.printHashMap();

	hm.insert(16, 256);

	hm.printHashMap();

	cout << hm[2] << endl; // 4 // cout << hm.operator[](2) << endl;

	cout << hm[7] << endl; // 49 // cout << hm.operator[](7) << endl;

	hm[7] = 0; // update the value of 7 from 49 to 0

	// hm.operator[](7) = 0; // same as hm[7] = 0

	hm.printHashMap();

	hm[12] = 144; // insert (12, 144)

	hm.printHashMap();

	// hm.operator[](12) = 144; // insert (12, 144)

	// hm[12] = 0; // update the value 12

	// cout << hm[100] << endl; // don't do this unless you've inserted 100

	return 0;
}
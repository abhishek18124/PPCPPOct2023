/*

Given an array of non-negative integers, find the maximum subarray XOR.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output:

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class trie {

	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) {

		// returns the maximum xor possible for n in just 1 xor operation

		int ans = 0; // to store maximum xor possible for n
		node* cur = root;

		for (int i = 31; i >= 0; i--) {

			int ithBit = (n >> i) & 1;

			if (ithBit) {

				// to make the ithBit of ans as 1, check if cur has leftChild(0)

				if (cur->left != NULL) {

					// you can set the ithBit of ans to 1

					ans += (1 << i); // 1 << i = 1 * 2^i // pow(2, i)
					cur = cur->left;

				} else {

					// you cannot set the ithBit of ans to 1
					cur = cur->right;

				}


			} else {

				// to make the ithBit of ans as 1, check if cur has rightChild(1)

				if (cur->right != NULL) {

					// you can set the ithBit of ans to 1
					ans += (1 << i);
					cur = cur->right;

				} else {

					// you cannot set the ithBit of ans to 1
					cur = cur->left;

				}

			}

		}

		return ans;

	}

	// time : O(n.32)
	// space: O(n.const)

	int maximumXOR(vector<int> x, int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) {
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}

};

void bruteForce(int arr[], int n) {

	// brute-force approach - time : O(n^3) space : O(1)

	int maxSoFar = 0; // to track the maximum subarray XOR

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// compute the xor of arr[i...j]
			int XOR = 0;
			for (int k = i; k <= j; k++) {
				XOR ^= arr[k];
			}
			maxSoFar = max(maxSoFar, XOR);
		}
	}

	cout << maxSoFar << endl;

}

void optimised1(int arr[], int n) {

	// using cxor - time : O(n^2) space : O(n) due cxor[]

	vector<int> cxor(n + 1);
	cxor[0] = 0;
	for (int i = 1; i <= n; i++) {
		cxor[i] = cxor[i - 1] ^ arr[i - 1];
	}

	int maxSoFar = 0; // to track the maximum subarray XOR

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// compute the xor of arr[i...j]
			int XOR = cxor[j + 1] ^ cxor[i];
			maxSoFar = max(maxSoFar, XOR);
		}
	}

	cout << maxSoFar << endl;

}

void optimised2(int arr[], int n) {

	// using true - time : O(n) space : O(n) due cxor[] and trie

	vector<int> cxor(n + 1);
	cxor[0] = 0;
	for (int i = 1; i <= n; i++) {
		cxor[i] = cxor[i - 1] ^ arr[i - 1];
	}

	trie t;
	for (int i = 0; i <= n; i++) {
		t.insert(cxor[i]);
	}

	cout << t.maximumXOR(cxor, n + 1) << endl;

}

int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	bruteForce(arr, n);

	optimised1(arr, n); // using cxor

	optimised2(arr, n); // using trie

	return 0;
}
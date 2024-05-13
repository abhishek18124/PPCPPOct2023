/*

Given an array of non-negative integers of size n, find the maximum possible XOR between
any two numbers present in the array.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output: 28
	Explaination: The maximum result is 5 ^ 25 = 28

	Input: x[] = {1, 2, 3, 4, 5, 6, 7}
	Output: 7
	Explaination: The maximum result is 1 ^ 6 = 7

*/

#include<iostream>
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

		cout << "maximum xor for " << n << " = " << ans << endl;
		cout << n << "^" << (ans ^ n) << "=" << ans << endl << endl;

		return ans;

	}

	// time : O(n.32)
	// space: O(n.const)

	int maximumXOR(int* x, int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) {
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};

int main() {

	int x[] = {2, 4, 5, 8, 10};
	int n = sizeof(x) / sizeof(int);

	// for (int i = 0; i < n - 1; i++) {
	// 	for (int j = i + 1; j < n; j++) {
	// 		cout << x[i] << "^" << x[j] << " = " << (x[i] ^ x[j]) << endl;
	// 	}
	// 	cout << endl;
	// }

	trie t;

	for (int i = 0; i < n; i++) {
		t.insert(x[i]);
	}

	cout << t.maximumXOR(x, n) << endl;

	return 0;
}
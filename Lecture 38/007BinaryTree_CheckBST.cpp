/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {

	if (root == NULL) {

		// tree is empty

		return INT_MAX;

	}

	while (root->left != NULL) {

		root = root->left;

	}

	return root->val;

}

int findMaximum(TreeNode* root) {

	if (root == NULL) {

		// tree is empty

		return INT_MIN;

	}

	while (root->right != NULL) {

		root = root->right;

	}

	return root->val;

}

// time : O(nh)

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {

		// tree is empty hence a BST

		return true;

	}

	// recursive case

	// 1. recursively, check if the leftSubtre is a BST

	bool leftIsBST = checkBST(root->left);

	// 2. recursively, check if the rightSubtree is a BST

	bool rightIsBST = checkBST(root->right);

	// 3. check if the BST prop. is satisfied at the root node

	bool rootIsBST = root-> val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBST and rightIsBST and rootIsBST;

}

class triple {

public :

	long long minVal;
	long long maxVal;
	bool isBST;

};

// time : O(n)

triple checkBSTEfficient(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {

		t.isBST = true;
		t.minVal = (long long)INT_MAX + 1;
		t.maxVal = (long long)INT_MIN - 1;

		return t;

	}

	// recursive case

	// 1. recursively, find the minVal, maxVal of the leftSubtree and also check it is a BST

	triple left = checkBSTEfficient(root->left);

	// 2. recursively, find the minVal, maxVal of the rightSubtree and also check it is a BST

	triple right = checkBSTEfficient(root->right);

	// 3. check if the BST property is satisfied at the root node

	bool rootIsBST = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.minVal = min(left.minVal, min(right.minVal, (long long)root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, (long long)root->val));
	t.isBST = left.isBST and right.isBST and rootIsBST;

	return t;

}

// time : O(n)

bool checkBSTEfficientTwo(TreeNode* root, long long lb, long long ub) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	return root->val > lb and root->val < ub and
	       checkBSTEfficientTwo(root->left, lb, root->val) and
	       checkBSTEfficientTwo(root->right, root->val, ub);

}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = checkBSTEfficient(root);

	t.isBST ? cout << "true" << endl : cout << "false" << endl;

	// INT_MIN <= node.val <= INT_MAX

	long long lb = (long long)INT_MIN - 1; // LLONG_MIN = -2^63
	long long ub = (long long)INT_MAX + 1; // LLONG_MAX = 2^63-1

	checkBSTEfficientTwo(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
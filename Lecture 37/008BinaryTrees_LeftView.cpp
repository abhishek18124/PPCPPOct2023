/*

given the pre-order traversal of a binary tree, output its right view.

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 30 60 70
*/

#include<iostream>
#include<queue>

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

TreeNode* buildTree() {

	// 1. read the val of the root TreeNode
	int val;
	cin >> val;

	if (val == -1) {
		// construct an empty tree and return the pointer to its root
		return NULL;
	}

	// 2. construct the root TreeNode
	TreeNode* root = new TreeNode(val);

	// 3. read the preOrder traversal of the leftSubtree & build the leftSubtree
	root->left = buildTree();

	// 4. read the preOrder traversal of the rightSubtree & build the rightSubtree
	root->right = buildTree();

	return root;

}

int maxLevel = -1; // to track the maximum level upto which you have printed the leftmost node

void printLeftViewRecursive(TreeNode* root, int level) {

	// base case

	if (root == NULL) {
		return;
	}

	// recursive case

	if (level > maxLevel) {

		// root is the rightmost node of the current level

		cout << root->val << " ";
		maxLevel = level;

	}

	printLeftViewRecursive(root->left, level + 1);
	printLeftViewRecursive(root->right, level + 1);

}


int main() {

	TreeNode* root = NULL;
	root = buildTree();

	printLeftViewRecursive(root, 0);

	cout << endl;

	return 0;
}
#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

// time : O(n)
// space: only due to function call O(n) if tree is skewed, O(logn) if tree is balanced
// space : O(h) where h is the height of the tree

// binary lifting ??

TreeNode* lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q) {

	// base case

	if (root == NULL) {

		// tree is empty

		return NULL;

	}

	if (root->val == p->val) {

		// lca(p, q) = p in the subtree of root

		return p;

	}

	if (root->val == q->val) {

		// lca(p, q) = q in the subtree of root

		return q;

	}

	// recursive case

	// org. problem : find the lca of p and q in the given tree

	// 1. recursively, find the lca of p and q in the leftSubtree

	TreeNode* left = lcaHelper(root->left, p, q);

	// 2. recursively, find the lca of p and q in the rightSubtree

	TreeNode* right = lcaHelper(root->right, p, q);

	if (left != NULL and right != NULL) {

		return root;

	} else if (left != NULL) { // right == NULL

		return left;

	} else if (right != NULL) { // left == NULL

		return right;

	}

	return NULL; // left == NULL and right == NULL

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	return lcaHelper(root, p, q); // dfs

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(3);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	return 0;
}
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

int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {

		// tree is empty

		return 0;

	}

	// recursive case

	int cnt = 0;

	if (root->val == targetSum) {

		// you've found one more path starts and ends at the root and whose sum is equal to targetSum

		cnt++;

	}

	// 1. recursively, count no. of paths in the leftSubtree starting at the root whose sum is equal to targetSum-root->val

	cnt += countPaths(root->left, targetSum - root->val);

	// 2. recursively, count no. of paths in the rightSubtree starting at the root whose sum is equal to targetSum-root->val

	cnt += countPaths(root->right, targetSum - root->val);

	return cnt;

}

// time : O(n^2)

int helper(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {

		// tree is empty

		return 0;

	}

	// recursive case

	// count no. paths in the given tree whose sum is equal to targetSum

	// 1. count the no. of paths in the given tree starting at the root node whose sum is equal to targetSum

	int x = countPaths(root, targetSum); // linear time

	// 2. count the no. of paths in the given tree not starting at the root whose sum is equal to targetSum

	// 2.1 recursively, count the no. of paths in the leftSubtree whose sum is equal to targetSum

	int y1 = helper(root->left, targetSum);

	// 2.2 recursively, count the no. of paths in the rightSubtree whose sum is equal to targetSum

	int y2 = helper(root->right, targetSum);

	int y = y1 + y2;

	return x + y; // const op

}

int pathSum(TreeNode* root, int targetSum) {

	return helper(root, targetSum);

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}
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

void printPath(vector<int>& path) {

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}

	cout << endl;

}

void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& allPaths) {

	// base case

	if (root == NULL) {

		// tree is empty

		return;

	}

	// root != NULL

	if (root->left == NULL and root->right == NULL) {

		if (root->val == targetSum) {

			// you've found a valid path from root-to-leaf

			path.push_back(root->val);
			// printPath(path);
			allPaths.push_back(path);
			path.pop_back();

		}

		return;

	}

	// recursive case

	path.push_back(root->val);

	helper(root->left, targetSum - root->val, path, allPaths);
	helper(root->right, targetSum - root->val, path, allPaths);

	path.pop_back(); // backtracking

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

	vector<int> path; // to track a root-to-leaf path in the given tree whose sum is equal targetSum
	vector<vector<int>> allPaths;

	helper(root, targetSum, path, allPaths);

	return allPaths;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;

	vector<vector<int>> allPaths = pathSum(root, targetSum);

	for (vector<int> path : allPaths) {
		for (int node_val : path) {
			cout << node_val << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
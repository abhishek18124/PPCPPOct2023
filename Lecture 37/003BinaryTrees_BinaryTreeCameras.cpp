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

class Triple {
public :

	int numCameras;
	bool isMonitored;
	bool hasCamera;

};

Triple helper(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {

		// tree is empty

		t.numCameras = 0;
		t.isMonitored = true;
		t.hasCamera = false;

		return t;

	}

	// recursive case

	Triple left = helper(root->left);
	Triple right = helper(root->right);

	// make a decision for the root node

	// option 1 : install camera at the root node

	if (!left.isMonitored || !right.isMonitored) {

		// install camera at the root node

		t.numCameras = left.numCameras + right.numCameras + 1;
		t.isMonitored = true;
		t.hasCamera = true;

		return t;

	}

	// option 2: don't install camera at the root node

	t.numCameras = left.numCameras + right.numCameras;
	t.isMonitored = left.hasCamera || right.hasCamera ? true : false;
	t.hasCamera = false;

	return t;

}

int minCameraCover(TreeNode* root) {

	Triple t = helper(root);

	if (t.isMonitored == false) {

		// root node of the given binary tree is not monitored, therefore install a camera at the root node

		return 1 + t.numCameras;

	}

	return t.numCameras;

}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// root->right = new TreeNode(0);
	// root->right->left = new TreeNode(0);
	// root->right->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	return 0;
}
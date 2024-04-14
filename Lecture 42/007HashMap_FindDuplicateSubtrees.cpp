/*
	https://leetcode.com/problems/find-duplicate-subtrees/
*/

class Solution {
public:

	unordered_set<TreeNode*> s;
	unordered_map<string, TreeNode*> treeMap;

	string dfs(TreeNode* root) {

		// base case

		if (root == NULL) {

			// tree is empty

			return "X"; // or any non-empty string

		}

		// recursive case

		string leftRepr  = dfs(root->left);
		string rightRepr = dfs(root->right);

		string subtreeRepr = to_string(root->val) + "-" + leftRepr + "-" + rightRepr;

		if (treeMap.find(subtreeRepr) == treeMap.end()) {

			// you have not yet seen subtreeRepr

			treeMap[subtreeRepr] = root;

		} else {

			// you've seen subtreeRepr previously i.e. you've found a duplicate subtree

			s.insert(treeMap[subtreeRepr]); // don't insert 'root' into s, it will lead to duplicate subtree inserted multiple times

		}

		return subtreeRepr;

	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		dfs(root);

		return vector<TreeNode*>(s.begin(), s.end()); // convert set<> into vector<>

		// vector<TreeNode*> ans(s.begin(), s.end());
		// return ans;

		// vector<TreeNode*> ans;
		// for (TreeNode* st : s) {
		// 	ans.push_back(st);
		// }
		// return ans;

	}
};
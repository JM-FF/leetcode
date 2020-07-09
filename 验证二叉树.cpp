/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return dfs(root, INT_MIN, INT_MAX);
	}
	bool dfs(TreeNode* root, long long lower, long long upper)
	{
		if (root == nullptr)
			return true;
		if (root->val<lower || root->val>upper)
			return false;
		return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
	}


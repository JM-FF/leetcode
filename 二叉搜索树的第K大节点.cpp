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
	int kthLargest(TreeNode* root, int k) {
		vector<int> tmp;
		dfs(root, tmp);
		return tmp[tmp.size() - k];
	}
private:

	void dfs(TreeNode* root,vector<int>& tmp)
	{
		while (!root)
			return;
		dfs(root->left, tmp);
		tmp.push_back(root->val);
		dfs(root->right, tmp);
	}
};

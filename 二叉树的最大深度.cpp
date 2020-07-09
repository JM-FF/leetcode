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
	int maxDepth(TreeNode* root) {
		int tmp = 0;
		int result = 0;
		dfs(root, tmp, result);
		return result;
	}
	void dfs(TreeNode* root, int& tmp, int& result)
	{
		if (root == NULL)
		{
			result = max(tmp, result);
			return;
		}
		tmp++;
		dfs(root->left, tmp, result);
		dfs(root->right, tmp, result);
        tmp--;
	}
};

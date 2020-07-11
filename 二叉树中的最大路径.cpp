class Solution {
public:
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return result;
	}
private:
	int dfs(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left = max (0,dfs(root->left));
		int right = max(0,dfs(root->right));
		int pass_tmp = root->val + max(left, right);
		result = max(result, max(pass_tmp, right + left + root->val));
		return pass_tmp;
	}

	int result = INT_MIN;
};

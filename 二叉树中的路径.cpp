class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> tmp;
		vector<vector<int>> result;
		int cur = 0;
		dfs(root, sum, cur, tmp, result);
		return result;
	}

private:
	void dfs(TreeNode* root, int sum, int& cur, vector<int> &tmp,vector<vector<int>> &result)
	{
		if (!root)
			return;
		tmp.push_back(root->val);
		cur += root->val;
		if (cur == sum&&root->left == nullptr&&root->right == nullptr)
		{
			result.push_back(tmp);
		}
		dfs(root->left, sum, cur, tmp, result);
		dfs(root->right, sum, cur, tmp, result);
		tmp.pop_back();
		cur -= root->val;
	}
};

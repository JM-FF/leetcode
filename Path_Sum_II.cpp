struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		vector<vector<int>> result;
		int path_value = 0;
		preorder(root, path_value, sum, path, result);
		return result;
	}

private:
	void preorder(TreeNode* root, int &path_value, int sum, vector<int> &path, vector<vector<int>>& result)
	{
		if (!root)
			return;
		path_value += root->val;
		path.push_back(root->val);
		if (!root->left && !root->right && sum == path_value)
			result.push_back(path);
		preorder(root->left, path_value, sum, path, result);
		preorder(root->right, path_value, sum, path, result);
		path_value -= root->val;
		path.pop_back();
	}
};

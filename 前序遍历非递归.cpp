class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> root_vec;
		vector<int> tmp;
		if (!root)
			return tmp;
		TreeNode* p = root;
		while (p || !root_vec.empty())
		{
			while (p)
			{
				root_vec.push(p);
				tmp.push_back(p->val);
				p = p->left;
			}
			if (!root_vec.empty())
			{
				p = root_vec.top();
				p = p->right;
				root_vec.pop();
			}
		}
		return tmp;
	}
};


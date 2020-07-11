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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> root_vec;
		vector<int> tmp;
		if (!root)
			return tmp;
		TreeNode* p = root;
		while (p||!root_vec.empty())
		{
			while (p)
			{
				root_vec.push(p);
				p = p->left;
			}
			if (!root_vec.empty())
			{
				p = root_vec.top();
				root_vec.pop();
				tmp.push_back(p->val);
				p = p->right;
			}
		}
		return tmp;
	}
};

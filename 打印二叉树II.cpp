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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> tmp;
		tmp.push(root);
		while (!tmp.empty())
		{
			vector<int> cur;
			int l = tmp.size();
			for (int i = 0; i < l; i++)
			{
				TreeNode* t = tmp.front();
				tmp.pop();
				cur.push_back(t->val);
				if (t->left != NULL)
					tmp.push(t->left);
				if (t->right != NULL)
					tmp.push(t->right);
			}
			result.push_back(cur);
		}
		return result;
	}
};

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
	vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if(root ==NULL)
            return result;
		queue<TreeNode*> tmp;
		tmp.push(root);
		while (!tmp.empty())
		{
			TreeNode* t = tmp.front();
			tmp.pop();
			result.push_back(t->val);
			if (t->left != NULL)
				tmp.push(t->left);
			if (t->right != NULL)
				tmp.push(t->right);
		}
		return result;
	}
};


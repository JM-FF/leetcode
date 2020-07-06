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
		if (!root)
			return 0;
		queue<TreeNode*> q;
		int result = 0;
		q.push(root);
		while (!q.empty())
		{
			queue<TreeNode*> tmp;
			while(!q.empty())
			{
				TreeNode* cur = q.front();
                q.pop();
				if (cur->left)
					tmp.push(cur->left);
				if (cur->right)
					tmp.push(cur->right);
			}
			q = tmp;
			result++;
		}
		return result;
	}
};

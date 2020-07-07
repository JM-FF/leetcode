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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root)
		{
			if (p->val > root->val && q->val > root->val)
			{
				root = root->right;
			}
			else if (p->val < root->val && q->val < root->val)
			{
				root = root->left;
			}
			else
				break;
		}
		return root;
	}
};



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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path;
		vector<TreeNode*> p_result;
		vector<TreeNode*> q_result;
		TreeNode* result = NULL;
		int len;
		int finish = 0;
		preorder(root, p, path, p_result, finish);
		path.clear();
		finish = 0;
		preorder(root, q, path, q_result, finish);
		if (p_result.size() < q_result.size())
		{
			len = p_result.size();
		}
		else
		{
			len = q_result.size();
		}

		for (int i = 0;i < len;i++)
		{
			if (p_result[i] == q_result[i])
				result = p_result[i];
		}
		return result;
	}
private:
	void preorder(TreeNode* root, TreeNode* p, vector<TreeNode*>& path, vector<TreeNode*>& result, int &finish)
	{
		if (!root || finish == 1)
			return;
		path.push_back(root);
		if (root == p)
		{
			result = path;
			finish = 1;
		}
		preorder(root->left, p, path, result, finish);
		preorder(root->right, p, path, result, finish);
		path.pop_back();
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode* last = nullptr;
		perorder(root, last);
	}

private:
	void perorder(TreeNode* node, TreeNode* &last)
	{
		if (!node){
			return;
		}
		if (!node->left&&!node->right){
			last = node;
			return;
		}

		TreeNode* left = node->left;   //备份左指针
		TreeNode* right = node->right;  //备份右指针
		TreeNode* left_last = nullptr;
		TreeNode* right_last = nullptr;

		if (left)
		{
			perorder(left, left_last);
			node->left = nullptr;
			node->right = left;
			last = left_last;
		}
		if (right)
		{
			perorder(right, right_last);
			if (left_last)
			{
				left_last->right = right;
			}
			last = right_last;
		}

	}
};

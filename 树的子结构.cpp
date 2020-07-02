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
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;
		if (result(A, B))
			return true;
		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}

	bool result(TreeNode* A, TreeNode* B)
	{
		if (B == NULL)
			return true;
		if (A == NULL || A->val != B->val)
			return false;
		return result(A->left,B->left)&&result(A->right,B->right);
	}
};

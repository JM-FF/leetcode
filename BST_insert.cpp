struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void BST_insert(TreeNode* node,TreeNode* insert_node)
{
	if (insert_node->val < node->val)
	{
		if (node->left)
		{
			BST_insert(node->left, insert_node);
		}
		else
		{
			node->left = insert_node;
		}
	}
	else
	{
		if (node->right)
		{
			BST_insert(node->right, insert_node);
		}
		else
		{
			node->right = insert_node;
		}
	}
}

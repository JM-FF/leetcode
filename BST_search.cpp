struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool BST_search(TreeNode*node, int value)
{
	if (node->val == value)
		return true;
	if (value < node->val){
		if (node->left){
			return BST_search(node->left, value);
		}
		else{
			return false;
		}
	}
	else{
		if (node->right){
			return BST_search(node->right, value);
		}
		else{
			return false;
		}
	}
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void BFS(TreeNode* root)
{
	queue<TreeNode*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		TreeNode* node = Q.front();
		Q.pop();
		cout << node->val << endl;
		if (node->left){
			Q.push(node->left);
		}
		if (node->right){
			Q.push(node->right);
		}
	}
}

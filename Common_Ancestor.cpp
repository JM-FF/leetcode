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
		vector<TreeNode*> node_p_path;
		vector<TreeNode*> node_q_path;
		int finish = 0;
		preorder(root, p, path, node_p_path, finish);  //求解p的路径
		finish = 0;
		path.clear();  //清空用来求解q
		preorder(root, q, path, node_q_path, finish);  //求解q

		int path_len_min;         //最小的路径长度
		if (node_p_path.size() < node_q_path.size())
		{
			path_len_min = node_p_path.size();
		}
		else{
			path_len_min = node_q_path.size();
		}

		TreeNode* result = 0;
		for (int i = 0; i < path_len_min; i++)
		{
			if (node_p_path[i]==node_q_path[i]){
				result = node_p_path[i];
			}
		}
		return result;
	}
private:
	void preorder(TreeNode* root, TreeNode* search, vector<TreeNode*> &path, vector<TreeNode*>& result, int &finish)
	{
		if (!root||finish)
			return;
		path.push_back(root);
		if (root == search)
		{
			result = path;
			finish = 1;
		}
		preorder(root->left, search, path, result,finish);
		preorder(root->right, search, path, result, finish);
		path.pop_back();
	}
};

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
	vector<int> rightSideView(TreeNode* root) {
		queue<pair<TreeNode*,int>> Q;
		vector<int> result;
		if (root)
			Q.push(make_pair(root, 0));
		while (!Q.empty())
		{
			TreeNode* node = Q.front().first;
			int depth = Q.front().second;
			Q.pop();
			if (result.size() == depth){
				result.push_back(node->val);
			}
			else{
				result[depth] = node->val;
			}
			if (node->left){
				Q.push(make_pair(node->left, depth + 1));
			}
			if (node->right){
				Q.push(make_pair(node->right, depth + 1));
			}
		}
        return result;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		queue<TreeNode*> tmp;
		tmp.push(root);
		int i = 1;
		while (!tmp.empty())
		{
			vector<int> cur;
			int l = tmp.size();
			for (int i = 0; i < l; i++)
			{
				TreeNode* t = tmp.front();
				tmp.pop();
				cur.push_back(t->val);
				if (t->left != NULL)
					tmp.push(t->left);
				if (t->right != NULL)
					tmp.push(t->right);
			}
			if (i == -1) {
				int m = cur.size() - 1;
				vector<int> ds(m + 1);
				for (int n : cur)
				{
					ds[m] = n;
					m--;
					if (m < 0)
						break;
				}
				result.push_back(ds);

			}
			else
				result.push_back(cur);
			i = -i;
		}
		return result;
	}
};

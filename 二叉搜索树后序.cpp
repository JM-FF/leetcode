class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		tmp = postorder;
		if (tmp.empty())
			return true;
		return dfs(0, tmp.size() - 1);
	}

private:
	vector<int> tmp;
	bool dfs(int l, int r)
	{
		if (l >= r)
			return true;
		int k = l;
		for (k = l; tmp[k] < tmp[r]; k++);
		for (int i = k; i < r; i++)
		{
			if (tmp[i] < tmp[r])
				return false;
		}

		return dfs(l, k-1) && dfs(k , r - 1);
	}
};

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> res;
		for (auto& i : matrix)
		{
			for (auto j : i)
			{
				if (res.size() < k)
					res.push(j);
				else
				{
					if (j < res.top())
					{
						res.push(j);
						res.pop();
					}
				}
			}
		}
		return res.top();
	}
};

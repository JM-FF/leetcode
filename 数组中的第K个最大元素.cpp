class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> res;
		for (auto m : nums)
		{
			if (res.size() < k)
				res.push(m);
			else {
				if (m > res.top())
				{
					res.push(m);
					res.pop();
				}
			}
		}
		return res.top();
	}
};

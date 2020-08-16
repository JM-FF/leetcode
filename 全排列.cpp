class Solution {
public:
	void dfs(vector<vector<int>>& result, vector<int>& nums, int location, int len)
	{
		if (location == len)
		{
			result.push_back(nums);
			return;
		}

		for (int i = location;i <len;i++)
		{
			swap(nums[i], nums[location]);
			dfs(result, nums, location+1, len);
			swap(nums[i], nums[location]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		dfs(result, nums, 0, nums.size());
		return result;

	}
};

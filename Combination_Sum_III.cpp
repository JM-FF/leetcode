class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
		vector<vector<int>> result;
		vector<int> item;
		set<vector<int>> set1;
		sort(nums.begin(), nums.end());
		generate(0, nums, item, result, set1, 0,target);

		return result;
	}
private:
	void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>&result, set<vector<int>>& set1, int sum,int target)
	{
		if (i >= nums.size() || sum > target)
			return;
		sum += nums[i];
		item.push_back(nums[i]);
		if (set1.find(item) == set1.end()&&sum==target)
		{
			result.push_back(item);
			set1.insert(item);
		}
		generate(i + 1, nums, item, result, set1, sum, target);
		item.pop_back();
		sum = sum - nums[i];
		generate(i + 1, nums, item, result, set1, sum, target);
	}
};

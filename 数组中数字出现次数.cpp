class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		unordered_map<int, int> tmp;
		vector<int> result;
		for (int i = 0;i < nums.size();i++)
		{
			tmp[nums[i]]++;
		}
		for (int i = 0;i < nums.size();i++)
		{
			if (tmp[nums[i]] == 1)
				result.push_back(nums[i]);
		}
		return result;
	}
};

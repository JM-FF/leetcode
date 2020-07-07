class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0, j = nums.size()-1;
		vector<int> result;
		while (i < j)
		{
			int sum = nums[i] + nums[j];
			if (sum == target)
			{
				result.push_back(nums[i]);
				result.push_back(nums[j]);
				break;
			}
			if (sum > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return result;
	}
};

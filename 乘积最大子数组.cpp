
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> max_dp(nums) , min_dp(nums);
		for (int i = 1;i < nums.size();i++)
		{
			max_dp[i] = max(nums[i] * max_dp[i - 1], max(nums[i], nums[i] * min_dp[i - 1]));
			min_dp[i] = min(nums[i] * max_dp[i - 1], min(nums[i], nums[i] * min_dp[i - 1]));
		}
		return *max_element(max_dp.begin(), max_dp.end());
	}
};

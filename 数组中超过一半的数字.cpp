class Solution {
public:
	int majorityElement(vector<int>& nums) 
	{
		if (nums.size() <= 1)
			return nums[0];
		sort(nums.begin(), nums.end());
		int tmp = nums[0];
		int m = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == tmp)
			{
				m++;
				if (m>nums.size() / 2)
					return nums[i];
			}
			else
			{
				m = 1;
				tmp = nums[i];
			}
		}
        return nums[0];
	}
};

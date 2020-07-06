class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int begin = 0;
		int end = nums.size()-1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == mid)
			{
				begin = mid + 1;
			}
			else
                end = mid-1;
		}
		return begin;
	}
};

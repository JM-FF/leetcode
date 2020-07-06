class Solution {
public:
	int search(vector<int>& nums, int target) {
        if(search_right(nums,target)==-1)
            return 0;
		return search_right(nums,target) - search_left(nums, target)+1;
	}
private:
	int search_left(vector<int>& nums, int target)
	{
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (mid == 0 || nums[mid] > nums[mid - 1])
				{
					return mid;
				}
				else
				{
					end = mid-1;
				}
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else if (nums[mid] < target)
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
	int search_right(vector<int>& nums, int target)
	{
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (mid  == nums.size()-1 || nums[mid] < nums[mid + 1])
				{
					return mid ;
				}
				else
				{
					begin = mid+1;
				}
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else if (nums[mid] < target)
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
};

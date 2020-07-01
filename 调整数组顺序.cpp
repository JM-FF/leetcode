//前后遍历数组
class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int fast = 0;
		int slow = 0;
		while (fast <= nums.size())
		{
			if (nums[fast] & 1 == 1)
			{
				swap(nums[fast], nums[slow]);
				slow++;
			}
			fast++;
		}
		return nums;
	}
};

//快慢指针

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int fast = nums.size() - 1;
		int slow = 0;
		while (slow < fast)
		{
			if ((nums[slow] & 1 ) !=0)
			{
				slow++;
				continue;
			}
			if ((nums[fast] & 1 )!= 1)
			{
				fast--;
				continue;
			}
			swap(nums[fast--], nums[slow++]);
		}
		return nums;
	}
};

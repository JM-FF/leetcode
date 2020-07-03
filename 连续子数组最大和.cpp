class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> result(nums.size());
		result[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (result[i-1] > 0)
				result[i] = result[i - 1] + nums[i];
            else
                result[i] = nums[i];
		}
		auto m = max_element(result.begin(), result.end());
		return *m;
	}
};



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
		for (int i = 1; i < size; i++)
		{
			if (nums[i - 1]>0)
				nums[i] += nums[i - 1];
		}

		return *max_element(nums.begin(), nums.end());
    }
};

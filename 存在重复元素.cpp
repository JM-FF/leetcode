class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> tmp;
		for (int m : nums)
		{
			tmp[m]++;
			if (tmp[m] > 1)
				return true;
		}
		return false;
	}
};

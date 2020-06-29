class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		set<int> tmp;
		for (int i : nums)
		{
			if (tmp.count(i) == 1)
				return i;
			else
				tmp.insert(i);
		}
		return NULL;
	}
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int> tmp;
		for (auto m : nums)
			tmp.insert(m);
		int max_num = 0;
		for (auto n : tmp)
		{
			if (!tmp.count(n - 1))
			{
				int count_num = n;
				int cur = 1;
				while (tmp.count(count_num + 1))
				{
					count_num++;
					cur++;
				}
				max_num = max(max_num, cur);
			}
		}
		return max_num;
	}
};

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> tmp;
		sort(intervals.begin(), intervals.end());
		for (int i = 0; i < intervals.size();)
		{
			int cur = intervals[i][1];
			int j = i + 1;
			while (j < intervals.size() && intervals[j][0] <= cur)
			{
				cur = max(cur, intervals[j][1]);
				j++;
			}
			tmp.push_back({ intervals[i][0],cur });
			i = j;
		}
		return tmp;
	}
};

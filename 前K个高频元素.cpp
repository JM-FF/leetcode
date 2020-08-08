class Solution {
public:
	//class slove
	//{
	//public:
	//	bool operator()(const pair<int, int>& m, const pair<int, int>& n)
	//	{
	//		return m.first > n.first;
	//	}
	//};
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> tmp;
		vector<int> result;
		for (auto m : nums)
			tmp[m]++;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cur;
		for (int i = 0;i < nums.size();i++)
		{
			if (tmp[nums[i]] > 0)
			{
				cur.push(make_pair(tmp[nums[i]],nums[i]));
				tmp[nums[i]] = 0;
			}
			if (cur.size() > k)
				cur.pop();
		}
		for (int i = 0; i < k;i++)
		{
			result.push_back(cur.top().second);
			cur.pop();
		}
		return result;
	}
};

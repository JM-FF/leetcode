class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> tmp;
		int res = -1;
		for (int i = 0;i < s.size();i++)
		{
			tmp[s[i]]++;
		}
		for (int i = 0;i < s.size();i++)
		{
			if (tmp[s[i]] == 1)
			{
				res = i;
				break;
			}
		}
		return res;
	}
};

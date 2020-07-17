class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (auto m : s)
		{
			res = res * 26 + (m - 'A' + 1);
		}
		return res;
	}
};

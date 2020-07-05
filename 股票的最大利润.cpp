class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxlen = INT_MAX;
		int result = 0;
		for (int n : prices)
		{
			if (maxlen > n)
				maxlen = n;
			else
				result = max(result, n - maxlen);
		}
		return result;
	}
};

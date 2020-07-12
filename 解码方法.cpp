class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0')
			return 0;
		int n = s.size();
		vector<int> dp(n);
		dp[0] = 1;
		for (int i = 1; i < n;i++)
		{
			if (s[i] != '0')
				dp[i] += dp[i - 1];
			if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
			{
				if (i - 2 >= 0)
					dp[i] += dp[i - 2];
				else
					dp[i]++;
			}
		}
		return dp[n-1];
	}
};

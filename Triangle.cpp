class Solution{
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 0)
			return 0;
		//------------------------------初始化dp
		vector<vector<int>> dp;
		for (int i = 0; i<triangle.size(); i++)
		{
			dp.push_back(vector<int>());
			for (int j = 0; j < triangle[i].size(); j++)
			{
				dp[i].push_back(0);
			}
		}
		//--------------------------------------------
		
		for (int i = 0; i < dp.size(); i++) //从三角形的最后一层计算，把最后一层赋值给dp
			dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
		//-----------------------------------------------------------
		
		for (int i = dp.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j < dp[i].size(); j++)
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];//动态规划方程  从下向上计算
			}
		}
		return dp[0][0];
	}
};

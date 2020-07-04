class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int x = grid.size();
		int y = grid[0].size();

		vector<vector<int>> tmp(x+1,vector<int>(y+1));
		for (int i = 1;i <= x;i++)
		{
			for (int j = 1;j <= y;j++)
			{
				tmp[i][j] = max(tmp[i - 1][j], tmp[i][j - 1]) + grid[i - 1][j - 1];
			}
		}
		return tmp[x][y];
	}
};

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0)
			return 0;
		int i_len = grid.size() - 1;
		int j_len = grid[0].size() - 1;
		int result = 0;
		for (int i = 0;i <= i_len;i++)
		{
			for (int j = 0;j <= j_len;j++)
			{
				if (grid[i][j] == '1')
				{
					result++;
					dfs(grid, i, j);
				}
			}
		}
		return result;
	}
private:
	void dfs(vector<vector<char>>& grid, int m, int n)
	{
		grid[m][n] = '0';
		for (int i = 0;i < 4;i++)
		{
			int x = m + dx[i];
			int y = n + dy[i];
			if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
				continue;
			if (grid[x][y] == '1')
				dfs(grid, x, y);
		}
	}

private:
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
};

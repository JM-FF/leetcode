class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;    //存放最终结果
		vector<vector<int>> mark;  //标记棋盘是否可以放置皇后的二维数组
		vector<string> location;  //存访某个摆放结果，完成一次递归后的结果

		for (int i = 0; i < n; i++)
		{
			mark.push_back(vector<int>());
			for (int j = 0; j < n; j++)
			{
				mark[i].push_back(0);
			}
			location.push_back("");
			location[i].append(n, '.');
		}
		generate(0, n, location, result, mark);
		return result;
	}
private:
	void put_down_the_queen(int x, int y, vector<vector<int>> &mark)
	{
		static const int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };//方向变量的定义
		static const int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

		mark[x][y] = 1;

		for (int i = 0; i < mark.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int new_x = x + i*dx[j];
				int new_y = y + i*dy[j];

				if (new_x >= 0 && new_x < mark.size() 
					&& new_y >= 0 && new_y < mark.size())//判断是否超出边界
					mark[new_x][new_y] = 1;
			}
		}
	}
	void generate(int k, int n, vector<string>&location, vector<vector<string>> &result, vector <vector<int>>&mark)
	{
		if (n == k)
		{
			result.push_back(location);
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (mark[k][i] == 0)
			{
				vector<vector<int>> tmp_mark = mark; //记录之前的值
				location[k][i] = 'Q';
				put_down_the_queen(k, i, mark);
				generate(k + 1, n, location, result, mark);
				mark = tmp_mark;
				location[k][i] = '.';
			}
		}
	}
};

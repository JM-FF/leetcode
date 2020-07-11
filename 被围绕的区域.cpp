class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;
		int len_i = board.size() - 1;
		int len_j = board[0].size() - 1;
		for (int i = 0;i <= len_i;i++)
		{
			for (int j = 0;j <= len_j;j++)
			{
				if (i == 0 || j == 0 || i == len_i || j == len_j)
				{
                    if(board[i][j] == 'O')
						search(board, i, j);
				}
			}
		}

		for (int i = 0;i <= len_i;i++)
		{
			for (int j = 0;j <= len_j;j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == '#')
					board[i][j] = 'O';
			}
		}
	}

private:
	void search(vector<vector<char>>& board,int i, int j)
	{
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#')
			return;
		board[i][j] = '#';
		search(board, i + 1, j);
		search(board, i - 1, j);
		search(board, i, j + 1);
		search(board, i, j - 1);
	}
};


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0)
			return false;
		vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (dfs(board, word, i, j, vis, 0))
					return true;
			}
		}
		return false;
	}
private:
	bool dfs(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>&vis, int id)
	{
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j] == true)
			return false;
		if (board[i][j] != word[id])
			return false;
		if (id == word.size() - 1)
			return true;
		vis[i][j] = true;
		bool flag = dfs(board, word, i + 1, j, vis, id + 1) ||
			dfs(board, word, i - 1, j, vis, id + 1) ||
			dfs(board, word, i, j + 1, vis, id + 1) ||
			dfs(board, word, i, j - 1, vis, id + 1);
		vis[i][j] = false;
		return flag;
	}
};

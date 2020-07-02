class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<bool>> tmp(m, vector<bool>(n, false));
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		int d = 0;
		int i = 0,x = 0,y = 0;
		for (int i = 0; i < m*n; i++)
		{
			result.push_back(matrix[x][y]);
			tmp[x][y] = true;

			int a = x + dx[d];
			int b = y + dy[d];
			if (a < 0 || a >= matrix.size() || b < 0 || b >= matrix[0].size() || tmp[a][b] == true)
			{
				d = (d + 1) % 4;
				a = x + dx[d];
				b = y + dy[d];
			}
			x = a;
			y = b;
		}
		return result;
	}
};

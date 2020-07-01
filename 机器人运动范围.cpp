class Solution {
public:
	int movingCount(int m, int n, int k) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		vector<vector<int>> visited(m, vector<int>(n, 0));
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		int result = 0;
		visited[0][0] = 1;
		while (!q.empty())
		{
			auto tmp = q.front();
			q.pop();
			int x = tmp.first;
			int y = tmp.second;
			result++;
			for (int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || visited[new_x][new_y] == 1||slove(new_x,new_y)>k)
					continue;
				q.push({ new_x, new_y });
				visited[new_x][new_y] = 1;
			}
		}
		return result;
	}

private:
	int slove(int m,int n)
	{
		int sum = 0;
		while (m > 0){
			sum += m % 10;
			m = m / 10;
		}
		while (n > 0){
			sum += n % 10;
			n = n / 10;
		}
		return sum;
	}
};

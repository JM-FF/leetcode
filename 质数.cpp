class Solution {
public:
	int countPrimes(int n) {
		if (1 == n || 2 == n)
		{
			return 0;
		}
		vector<int> tmp(n+1, 0);
		int cur = 0;
		for (int i = 2;i < n;i++)
		{
			if (tmp[i] == 0)
				cur++;
			for (int j = i + i;j < n;j += i)
			{
				tmp[j] = 1;
			}
		}
		return cur;
	}
};

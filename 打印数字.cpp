class Solution {
public:
	vector<int> printNumbers(int n) {
		int sum = 0;
		vector<int> tmp;
		for (int i = 0; i < n; i++)
		{
			sum = (sum * 10) + 9;
		}
		for (int i = 1; i <= sum; i++)
			tmp.push_back(i);
		return tmp;
	}
};

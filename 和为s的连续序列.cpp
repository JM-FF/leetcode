
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1;
		int j = 1;
		int sum = 0;
		vector<vector<int>> result;
		while (i<=target/2)
		{
			if (sum > target)
			{
				sum -= i;
				i++;
			}
			else if (sum < target)
			{
				sum += j;
				j++;
			}
			else
			{
				vector<int> tmp;
				for (int m = i;m < j;m++)
				{
					tmp.push_back(m);
				}
				result.push_back(tmp);
				sum -= i;
				i++;
			}
		}
		return result;
	}
};

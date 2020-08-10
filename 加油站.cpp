class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		vector<int>diff;
		for (int i = 0; i < gas.size();i++)
		{
			diff.push_back(gas[i] - cost[i]);
		}

		for (int i = 0; i < gas.size();i++)
		{
			if (diff[i] >= 0)
			{
				int cap = diff[i];
				int j = i;
				j++;
				j %= gas.size();

				while (j != i && cap >= 0)
				{
					cap += diff[j];
					j++;
					j %= gas.size();
				}
				if (j == i&&cap>=0)
					return j;
			}
		}
		return -1;
	}
};

class Solution {
public:
	int cuttingRope(int n) {
		if (n == 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		int i = n % 3;
		int j = n / 3;
		if (i == 1){
			return pow(3, j - 1) * 4;
		}
		else if (i == 2)
		{
			return pow(3, j) * 2;
		}
		else
			return pow(3, j);
	}
};

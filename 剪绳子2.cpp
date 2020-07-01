class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3)
			return n - 1;
		long tmp = 1;
		while (n > 4)
		{
			tmp *= 3;
			tmp %= 1000000007;
			n -= 3;
		}
		return n*tmp%1000000007;
	}
};

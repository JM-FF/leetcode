class Solution {
public:
	int hammingWeight(uint32_t n) {
		int i = 0;
		while (n > 0)
		{
			if ((n & 1) == 1)
				i++;
			n >>=1;
		}
		return i;
	}
};

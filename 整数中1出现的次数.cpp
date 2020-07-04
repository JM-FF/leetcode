
class Solution {
public:
	int countDigitOne(int n) {
		vector<int>  tmp;
		while(n)
		{
			tmp.push_back(n%10);
			n /=10;
		}
		int result = 0;
		for(int i = tmp.size()-1;i>=0;i--)
		{
			int left = 0, right = 0, x = 1;
			for(int j = tmp.size()-1;j>i;j--)
			{
				left = left*10+tmp[j];
			}
			for(int k = i-1; k >= 0; k--)
			{
				right = right*10 +tmp[k];
				x *= 10;
			}
			result = result+ left*x;
			if(tmp[i] == 1)
				result = result + right +1;
			else if(tmp[i]>1)
				result = result+x;
		}

		return result;
	}
};

class Solution {
public:
	string replaceSpace(string s) {
		int len1 = s.size() - 1;
		for (int i = 0; i <= len1; i++)
		{
			if (s[i] == ' ')
				s += "00";
		}
		int len2 = s.size() - 1;
		for (int i = len1; i >= 0; i--)
		{
			char m = s[i];
			if (s[i] == ' ')
			{
				s[len2--] = '0';
				s[len2--] = '2';
				s[len2--] = '%';
			}
			else{
				s[len2--] = m;
			}
		}
		return s;
	}
};

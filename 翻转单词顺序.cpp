class Solution {
public:
	string reverseWords(string s) {
		int k = 0;
		int m = s.size() - 1;
		while (k <=s.size() - 1 && s[k] == ' ')
			k++;
		while (m >= 0 && s[m] == ' ')
			m--;
		string tmp = "";
		string result = "";
		for (int i = k;i <= m;i++)
		{
			if (s[i] != ' ')
				tmp += s[i];
			else
			{
				while (s[i] == ' ')
					i++;
				i--;
				result += str_ex(tmp);
				result += " ";
				tmp = "";
			}
		}
		if (!tmp.empty())
			result += str_ex(tmp);
		return str_ex(result);
	}

	string str_ex(string s)
	{
		int i = 0;
		int j = s.size() - 1;
		while (i < j)
			swap(s[i++], s[j--]);
		return s;
	}
};

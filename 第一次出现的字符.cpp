#include<unordered_map>
class Solution {
public:
	char firstUniqChar(string s) {
		if (s == "")
			return ' ';
		unordered_map<char, int> tmp;
		for (int i = 0;i < s.size();i++)
		{
			tmp[s[i]]++;
		}

		for (int i = 0;i < s.size();i++)
		{
			if (tmp[s[i]] == 1)
            {
                return s[i];
            }
		}
		return ' ';
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> tmp;
		int maxlen = 0;
		for (int i = 0;i < s.size();i++)
		{
			int len = 0;
            tmp.clear();
			tmp.insert(s[i]);
			len++;
			for (int j = i + 1;j < s.size();j++)
			{
				if (tmp.count(s[j]))
				{
					break;
				}
				else
				{
					tmp.insert(s[j]);
					len++;
				}
			}
			if (len > maxlen)
				maxlen = len;
		}
		return maxlen;
	}
};



//双指针
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> tmp;
		int maxlen = 0;
		int right = 0;
		for (int i = 0;i < s.size();i++)
		{
			while (right < s.size() && !tmp.count(s[right]))
			{
				tmp.insert(s[right]);
				right++;
			}
			maxlen = max(maxlen, right - i);
			if (right == s.size())
				break;
			tmp.erase(s[i]);
		}
		return maxlen;
	}
};

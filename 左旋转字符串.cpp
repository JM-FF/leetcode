class Solution {
public:
	string reverseLeftWords(string s, int n) {
		string tmp = "";
		string cur = "";
		int i = 0;
		while (i < n)
		{
			tmp += s[i++];
		}
		while (i < s.size())
		{
			cur += s[i++];
		}
		return cur + tmp;
	}
};

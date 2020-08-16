class Solution {
public:
	bool isPalindrome(string s) {
		string tmp;
		for (auto m : s)
		{
			if (isalnum(m))
				tmp += tolower(m);
		}
		string m ( tmp.rbegin(),tmp.rend() );
		return tmp == m;
	}
};
class Solution {
public:
	bool isPalindrome(string s) {
		string tmp;
		for (auto m : s)
		{
			if (isalnum(m))
				tmp += tolower(m);
		}
		int l = 0;
		int r = tmp.size() - 1;
		while (l < r)
		{
			if (tmp[l] != tmp[r])
				return false;
			l++;
			r--;
		}
		return true;
	}
};
class Solution {
public:
	bool isPalindrome(string s) {
		int l = 0;
		int r = s.size() - 1;
		while (l < r)
		{
			while (l < r && !isalnum(s[l]))
			{
				l++;
			}
			while (l < r && !isalnum(s[r]))
			{
				r--;
			}

			if (l < r)
			{
				if (tolower(s[l]) != tolower(s[r]))
					return false;
				l++;
				r--;
			}
		}
		return true;
	}
};

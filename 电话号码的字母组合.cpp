//回溯法
class Solution {
public:
	map<char,string> tmp = {
		{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
		{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
	};
	vector<string> res;
	string cur;

	void dfs(int index, string digits)
	{
		if (index == digits.size())
		{
			res.push_back(cur);
		}
		for (int i = 0;i < tmp[digits[index]].size();i++)
		{
			cur.push_back(tmp[digits[index]][i]);
			dfs(index + 1, digits);
			cur.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
			return res;
		dfs(0, digits);
		return res;
	}
};

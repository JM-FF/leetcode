class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> mp;
        dfs("", n, n, mp);
        return mp;
    }
    void dfs(string tmp, int left, int right, vector<string>& mp)
    {
        if (left == 0 && right == 0)
        {
            mp.push_back(tmp);
            return;
        }
        if (left > 0)
            dfs(tmp + '(', left - 1, right, mp);
        if (right > left)
            dfs(tmp + ')', left, right - 1, mp);
    }
};


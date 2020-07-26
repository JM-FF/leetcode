class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        unordered_map<char,char> mp = { { '{','}' }, { '(',')' }, { '[',']' } };
        for (auto m : s)
        {
            if (m == '(' || m == '[' || m == '{')
            {
                tmp.push(mp[m]);
            }
            else
            {
                if (tmp.empty())
                    return false;
                if (tmp.top() == m)
                    tmp.pop();
                else
                    return false;
            }
        }
        if (!tmp.empty())
            return false;
        return true;
    }
};


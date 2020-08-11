//横向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string cur = strs[0];
        for (int i = 1;i < strs.size();i++)
        {
            cur = cmp(cur, strs[i]);
            if (cur.empty())
                break;
        }
        return cur;
    }
    string cmp(const string& str1, const string& str2)
    {
        int len = min(str1.size(), str2.size());
        int tmp = 0;
        while (tmp < len && str1[tmp] == str2[tmp])
        {
            tmp++;
        }
        return str1.substr(0, tmp);
    }
};

//分治
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        else
        {
            return longcmp(0, strs.size() - 1, strs);
        }
    }
    string longcmp(int left, int right, vector<string>& strs)
    {
        if (left == right)
            return strs[left];
        int mid = (left + right) / 2;
        string left_s = longcmp(left, mid, strs);
        string right_s = longcmp(mid + 1, right, strs);
        return cmp(left_s, right_s);
    }
    string cmp(const string& str1, const string& str2)
    {
        int len = min(str1.size(), str2.size());
        int tmp = 0;
        while (tmp < len && str1[tmp] == str2[tmp])
        {
            tmp++;
        }
        return str1.substr(0, tmp);
    }
};



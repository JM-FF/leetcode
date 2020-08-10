class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> tmp;
        vector<int> res;
        if(nums1.size()>nums2.size())
        {
            for(auto m : nums1)
            {
                tmp[m]++;
            }
            for(auto m:nums2)
            {
                if(tmp[m]>0)
                {
                    res.push_back(m);
                    tmp[m]--;
                }
            }
        }
        else
        {
            for(auto m : nums2)
            {
                tmp[m]++;
            }
            for(auto m:nums1)
            {
                if(tmp[m]>0)
                {
                    res.push_back(m);
                    tmp[m]--;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> tmp;
        vector<int> res;
        for(auto m : nums1)
        {
            tmp[m]++;
        }
        for(auto m:nums2)
        {
            if(tmp[m]>0)
            {
                res.push_back(m);
                tmp[m]--;
            }
        }
        return res;
    }
};

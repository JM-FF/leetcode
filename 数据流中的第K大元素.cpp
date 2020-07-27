//使用最小堆默认是最大堆
class KthLargest {
    int _k;
    priority_queue<int, vector<int>, greater<int>> mp;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int m : nums)
        {
            mp.push(m);
            if (mp.size() > k)
                mp.pop();
        }
        _k = k;
    }
    int add(int val) {
        mp.push(val);
        if (mp.size() > _k)
            mp.pop();
        return mp.top();
    }
};
//使用set进行
#include<set>
class KthLargest2 {
    int _k;
    set<int> sp;
public:
    KthLargest2(int k,vector<int>& nums) {
        for (int m : nums)
        {
            sp.insert(m);
            if (sp.size() > k)
                sp.erase(sp.begin());
        }
        _k = k;
    }
    int add(int val) {
        sp.insert(val);
        if (sp.size() > _k)
            sp.erase(sp.begin());
        return *sp.begin();
    }
};



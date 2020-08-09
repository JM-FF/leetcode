//哈希
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>  tmp;
        for(auto m : nums)
            tmp[m]++;
        for(int i = 0; i < nums.size();i++)
        {
            if(tmp[nums[i]]>1)
                return nums[i];
        }
        return 0;
    }
};
//哈希
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>  tmp;
        for(auto m : nums)
        {
            if(tmp[m]++>0)
                return m;
            //tmp[m]++;
        }
        return 0;
    }
};

//快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;
        while(1)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        int find = 0;
        while(1)
        {
            slow = nums[slow];
            find = nums[find];
            if(slow == find)
                break;
        }
        return find;
    }
};


class Solution {
public:
    int slove(int n)
    {
        int sum = 0;
        while (n)
        {
            int i = n % 10;
            sum += i * i;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int,int> res;
        while (1)
        {
            int sum = slove(n);
            if (sum == 1)   return true;
            if (res[sum] > 0)   return false;
            res[sum]++;
            n = sum;
        }
        return false;
    }
};

class Solution {
public:
    int slove(int n)
    {
        int sum = 0;
        while (n)
        {
            int i = n % 10;
            sum += i * i;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow = slove(slow);
            fast = slove(fast);
            fast = slove(fast);
        }while(slow != fast);
        return slow == 1;
    }
};


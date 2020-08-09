//超时
class MedianFinder {
public:
    vector<double> nums;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        nums.push_back(num);
    }
    double findMedian() {
        sort(nums.begin(), nums.end());
        if (nums.size() & 1)
        {
            return nums[nums.size() / 2];
        }
        else
        {
            int tmp = nums[nums.size() / 2] + nums[nums.size() / 2 - 1];
            // if(tmp%2==1)
            //     return tmp/2+0.5;
            return tmp / 2;
        }
    }
};


//排序算法优化插入法
class MedianFinder {
public:
    vector<double> nums;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        if (nums.empty())
            nums.push_back(num);
        else
            nums.insert(lower_bound(nums.begin(), nums.end(), num), num);
    }
    double findMedian() {
        //sort(nums.begin(), nums.end());
        if (nums.size() & 1)
        {
            return nums[nums.size() / 2];
        }
        else
        {
            double tmp = nums[nums.size() / 2] + nums[nums.size() / 2 - 1];
            // if(tmp%2==1)
            //     return tmp/2+0.5;
            return tmp / 2;
        }
    }
};


//大顶堆和小顶堆  一人存一半；
class MedianFinder {
public:
    priority_queue<double> big;
    priority_queue<double,vector<double>,greater<double>> small;
    void addNum(int num) {
        small.push(num);
        big.push(small.top());
        small.pop();

		//进行平衡
        if(small.size()<big.size())
        {
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if(small.size()>big.size())
            return small.top();
        else
            return (small.top()+big.top())/2;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



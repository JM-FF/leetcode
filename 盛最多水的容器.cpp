class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int l = 0;
        int r = height.size()-1;
        int max_wator = 0;
        while(l<r)
        {
            int area =min(height[l],height[r])*(r-l);
            max_wator = max(max_wator,area);
            if(height[l]>height[r])
                r--;
            else
                l++;
        }
        return max_wator;
    }
};


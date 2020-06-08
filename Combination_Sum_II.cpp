class Solution {
public: 
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
                vector<vector<int>> result;
                vector<int> item;
                set<vector<int>> set1;
                sort(nums.begin(), nums.end());
                result.push_back(item);
                generate(0, nums, item, result, set1);
                vector<vector<int>> target_result;
                for(int i = 0;i<result.size();i++)
                {
                    int sum = 0;
                    for(int j = 0;j<result[i].size();j++)
                    {
                        sum+=result[i][j];
                    }
                    if(sum == target)
                        target_result.push_back(result[i]);
                }

                return target_result;
        }
private:
        void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>&result, set<vector<int>>& set1)
        {
                if (i >= nums.size())
                        return;
                item.push_back(nums[i]);
                if (set1.find(item) == set1.end())
                {
                        result.push_back(item);
                        set1.insert(item);
                }
                generate(i + 1, nums, item, result, set1);
                item.pop_back();
                generate(i + 1, nums, item, result, set1);
        }
};


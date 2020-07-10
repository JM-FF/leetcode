/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        int tmp = nums.size()/2;
        TreeNode* root = new TreeNode(nums[tmp]);
        TreeNode* p = root;
        vector<int> l_nums,r_nums;
        for(int i = 0; i < tmp;i++)
            l_nums.push_back(nums[i]);
        for(int i = tmp+1;i<nums.size();i++)
            r_nums.push_back(nums[i]);
        p->left = sortedArrayToBST(l_nums);
        p->right = sortedArrayToBST(r_nums);
        return root;
    }
};

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* p = root;
        vector<int> lpreorder;
        vector<int> rperorder;
        vector<int> linorder;
        vector<int> rinorder;
        int tmp = 0;
        for(int i = 0 ;i < inorder.size();i++)
        {
            if(inorder[i]==preorder[0])
                tmp = i;
        }
        for(int i = 1;i <= tmp;i++)
        {
            lpreorder.push_back(preorder[i]);
        }
        for(int i = tmp+1;i <= preorder.size()-1;i++)
        {
            rperorder.push_back(preorder[i]);
        }
        for(int i = 0;i<tmp;i++)
        {
            linorder.push_back(inorder[i]);
        }
        for(int i = tmp+1;i < inorder.size();i++)
        {
            rinorder.push_back(inorder[i]);
        }
        p->left = buildTree(lpreorder,linorder);
        p->right = buildTree(rperorder,rinorder);
        return root;
    }
};

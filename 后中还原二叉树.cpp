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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()== 0)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        TreeNode* p = root;
        vector<int> linorder,rinorder,lpostorder,rpostorder;
        int tmp = 0;
        for(int i = 0 ;i < inorder.size();i++)
        {
            if(inorder[i]==postorder[postorder.size()-1])
                tmp = i;
        }
        for(int i = 0;i < tmp;i++)
        {
            linorder.push_back(inorder[i]);
        }
        for(int i = tmp+1;i < inorder.size();i++)
        {
            rinorder.push_back(inorder[i]);
        }
        for(int i =  0; i < tmp;i++)
        {
            lpostorder.push_back(postorder[i]);
        }
        for(int i = tmp;i<postorder.size()-1;i++)
        {
            rpostorder.push_back(postorder[i]);
        }
        p->left = buildTree(linorder,lpostorder);
        p->right = buildTree(rinorder,rpostorder);
        return root;
    }
};

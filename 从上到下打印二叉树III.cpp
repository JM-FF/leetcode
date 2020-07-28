//笨办法  在102题的基础上根据标志位进行每次的vector遍历翻转
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> tmp;
        tmp.push(root);
        int i = 1;
        while (!tmp.empty())
        {
            vector<int> cur;
            int l = tmp.size();
            for (int i = 0; i < l; i++)
            {
                TreeNode* t = tmp.front();
                tmp.pop();
                cur.push_back(t->val);
                if (t->left != NULL)
                    tmp.push(t->left);
                if (t->right != NULL)
                    tmp.push(t->right);
            }
            if (i == -1){
                int m = cur.size() - 1;
                vector<int> ds(m + 1);
                for (int n : cur)
                {
                    ds[m] = n;
                    m--;
                    if (m < 0)
                        break;
                }
                result.push_back(ds);
            }else
            result.push_back(cur);
            i = -i;
        }
        return result;
    }
};
//采用双端队列或者两个栈进行实现
//前出后进，后进前出
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        deque<TreeNode*> tmp;
        tmp.push_back(root);
        int flag = 1;
        while (!tmp.empty())
        {
            int len = tmp.size();
            vector<int> cur;
            for (int i = 0;i < len;i++)
            {
                if (flag == 1)
                {
                    if (tmp.back()->left)
                        tmp.push_front(tmp.back()->left);
                    if (tmp.back()->right)
                        tmp.push_front(tmp.back()->right);
                    cur.push_back(tmp.back()->val);
                    tmp.pop_back();
                }
                else
                {
                    if (tmp.front()->right)
                        tmp.push_back(tmp.front()->right);
                    if (tmp.front()->left)
                        tmp.push_back(tmp.front()->left);
                    cur.push_back(tmp.front()->val);
                    tmp.pop_front();
                }
            }
            result.push_back(cur);
            flag = -flag;
        }
        return result;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
        if(!root)
            return NULL;
		queue<Node*> q;
		q.push(root);
		queue<Node*> tmp;
		while (!q.empty())
		{
			Node* p = q.front();
			if (p->left)
				tmp.push(p->left);
			if (p->right)
				tmp.push(p->right);
			q.pop();
			if (q.empty())
			{
				p->next = NULL;
				q = tmp;
				while (!tmp.empty())
					tmp.pop();
			}
			else
			{
				Node* cur = q.front();
				p->next = cur;
			}
		}
		return root;
	}
};

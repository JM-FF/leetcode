/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int> tmp;
		vector<int> result;
		while (head){
			tmp.push(head->val);
			head = head->next;
		}
		while (!tmp.empty())
		{
			result.push_back(tmp.top());
			tmp.pop();
		}
		return result;
	}
};

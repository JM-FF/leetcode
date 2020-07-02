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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* root = new ListNode(-1);
		ListNode* tmp = root;
		while (l1&&l2)
		{
			if (l1->val < l2->val)
			{
				root->next = l1;
				root = root->next;
				l1 = l1->next;
			}
			else
			{
				root->next = l2;
				root = root->next;
				l2 = l2->next;
			}
		}
		if (l1)
			root->next = l1;
		else
			root->next = l2;

		return tmp->next;
	}
};

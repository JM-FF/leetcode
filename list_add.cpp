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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* ret = new ListNode(1);
		ListNode* tmp = ret;

		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				tmp->next = l2;
				return ret->next;
			}
			if (l2 == NULL)
			{
				tmp->next = l1;
				return ret->next;
			}
			if (l1->val > l2->val)
			{
				tmp->next = l2;
				tmp = tmp->next;
				l2 = l2->next;
			}
			else
			{
				tmp->next = l1;
				tmp = tmp->next;
				l1 = l1->next;
			}
		}
		return ret->next;
	}
};

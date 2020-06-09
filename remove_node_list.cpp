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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* tmp = nullptr;
		for (int i = 0; i < n; i++)
		{
			fast = fast->next;
		}
		while (fast)
		{
			tmp = slow;
			slow = slow->next;
			fast = fast->next;
		}
        if(tmp!=nullptr)
		    tmp->next = slow->next;
        else
            return head->next;
		return head;
	}
};

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* fast = headA;
		ListNode* slow = headB;
        int l1 = 0;
        int l2 = 0;
		while (1)
		{
            if(fast == slow)
                return fast;
			if (fast == NULL)
			{
				fast = headB;
                l1++;
			}
			else{
				fast = fast->next;
			}

			if (slow == NULL)
			{
				slow = headA;
                l2++;
			}
			else{
				slow = slow->next;
			}
            if(l1 == 2|| l2 == 2)
                 return NULL;
		}
		return fast;
	}
};


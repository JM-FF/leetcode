class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> m;
        while (head)
        {
            m[head]++;
            if (m[head] > 1)
                return true;
            head = head->next;
        }
        return false;
    }
    bool hasCycle2(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

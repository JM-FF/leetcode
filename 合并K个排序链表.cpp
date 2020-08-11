class Solution {
public:
	struct slove
	{
		bool operator()(const ListNode* m, const ListNode* n)
		{
			return m->val < n->val;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, slove> tmp;
		for (auto m : lists)
		{
			while (m)
			{
				tmp.push(m);
				m = m->next;
			}
		}
		ListNode* res = NULL;
		while (tmp.size() > 0)
		{
			tmp.top()->next = res;
			res = tmp.top();
			tmp.pop();
		}
		return res;
	}
};

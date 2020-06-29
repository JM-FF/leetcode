/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		map<Node*, int> node_map;
		vector<Node*> node_vec;
		Node* ptr = head;
		for (int i = 0; ptr != NULL; i++)
		{
			node_vec.push_back(new Node(ptr->val));
			node_map[ptr] = i;
			ptr = ptr->next;
		}
		node_vec.push_back(0);
		ptr = head;
		for (int i = 0; ptr != NULL; i++)
		{
			node_vec[i]->next = node_vec[i + 1];
			if (ptr->random != NULL)
			{
				int m = node_map[ptr->random];
				node_vec[i]->random = node_vec[m];
			}
			ptr = ptr->next;
		}
		return node_vec[0];
		
	}
};

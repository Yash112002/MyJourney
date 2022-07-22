
#define Node ListNode
#define data val
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		// step 1 : creating 2 dummy list, to store the data accordingly
		Node* temp = head;
		Node* d1 = new Node(-1);
		Node* d2 = new Node(-1);
		Node* lt = d1;
		Node* mt = d2;
		// traversing through the linked list and checking for the conditions
		while(temp)
		{
			if(temp->data < x)
			{
				lt->next = new Node(temp->data);
				lt = lt->next;
			}
			else
			{
				mt->next = new Node(temp->data);
				mt = mt->next;
			}
			temp = temp->next;
		}
		// udating the starting and ending point of the required linkedlist
		if(d1->next == NULL)
		{
			mt->next = NULL;
			return d2->next;
		}
		else
		{
			lt->next = d2->next;
			mt->next = NULL;
			return d1->next;
		}
	}
};

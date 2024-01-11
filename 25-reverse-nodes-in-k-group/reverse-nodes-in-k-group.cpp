class Solution 
{
public:
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (k == 1)
		{
			return head;
		}

		ListNode* prev = head;
		ListNode* temp = head;
		ListNode* currHead = head;
		ListNode* lastTail = NULL;


		ListNode* ans = head;

		int count = 0;
		while (prev)
		{
			if (count == k)
			{
				auto t  = reverseLinkedList(currHead, temp);
				if (ans == head)
					ans = t.first;
				if (lastTail)
					lastTail->next = t.first;
				lastTail = t.second;
				lastTail->next = temp;		//Temp connection to rest of list in case the rest of the elements dont form a k group
				count = 0;
				currHead = temp;
			}
			count++;
			prev = temp;
            if (temp)
			    temp = temp->next;
		}
		return ans;
	}

	std::pair<ListNode*, ListNode*> reverseLinkedList(ListNode* head, ListNode* tail)
	{
		ListNode* temp = head;
		ListNode* prev = NULL;
		ListNode* nextNode = NULL;

		while (temp != tail)
		{
			nextNode = temp->next;
			temp->next = prev;
			prev = temp;
			temp = nextNode;
		}
		return std::pair(prev, head);	//prev is the head of the reversed subList and head is the tail of the sublist.
	}
};
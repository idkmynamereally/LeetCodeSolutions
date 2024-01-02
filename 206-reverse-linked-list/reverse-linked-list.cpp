class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* temp = head;
        ListNode* nextNode;
        ListNode* prevNode = NULL;
        while (temp != NULL)
        {
            nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;

            temp = nextNode;
        }
        return prevNode;
    }
};
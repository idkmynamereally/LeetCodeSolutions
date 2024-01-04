class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head->next == NULL)
            return NULL;
        ListNode* trackBehind = head;
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL)    //After this loop trackBehind is the node before the node that has to be deleted.
        {
            if (count > n)
                trackBehind = trackBehind->next;
            count++;
            temp = temp->next;
        }
        if ((n - count) == 0)
        {
            head = head->next;
        }
        else if (trackBehind == head)
            head->next = head->next->next;
        else
            trackBehind->next = trackBehind->next->next;
        return head;
    }
};
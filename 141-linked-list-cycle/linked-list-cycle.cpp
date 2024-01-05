class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        ListNode* slowP = head;
        ListNode* fastP = head;
        while (fastP != NULL && fastP->next != NULL)
        {
            slowP = slowP->next;
            fastP = fastP->next->next;
            if (slowP == fastP)
                return true;
        }
        return false;
    }
};
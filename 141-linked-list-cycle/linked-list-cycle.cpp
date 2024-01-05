class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        ListNode* slowP = head;
        ListNode* fastP = head;
        bool start = false;
        while (fastP != NULL && fastP->next != NULL)
        {
            if (start && slowP == fastP)
                return true;
            start = true;
            slowP = slowP->next;
            fastP = fastP->next->next;
        }
        return false;
    }
};
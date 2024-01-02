class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        ListNode n = ListNode();
        ListNode* newHead = &n;
        ListNode* temp = newHead;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 == NULL)
        {
            temp->next = list2;
        }
        else
        {
            temp->next = list1;
        }
        newHead = newHead->next;
        return newHead;
    }
};
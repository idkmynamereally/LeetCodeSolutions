class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1)
            return head;
        return recurse(head, k);
    }

    ListNode* recurse(ListNode* head, int k)
    {
        int count = 0;
        ListNode* nextNode = head;

        while (nextNode && count != k) {
            count++;
            nextNode = nextNode->next;
        }

        if (count != k) {
            return head; //do
        }

        ListNode* newTail = head;
        ListNode* newHead = nullptr;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (temp != nextNode)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        newTail->next = recurse(nextNode, k);
        newHead = prev;

        return newHead;
    }
};
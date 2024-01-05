/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans = NULL;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* back = NULL;
        int carry = 0;
        while (temp1 && temp2)
        {
            temp1->val = temp1->val + temp2->val + carry;
            carry = 0;
            if (temp1->val > 9)
            {
                temp1->val = temp1->val - 10;
                carry = 1;
            }
            back = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1)
        {
            temp1->val = temp1->val + carry;
            carry = 0;
            if (temp1->val > 9)
            {
                temp1->val = temp1->val - 10;
                carry = 1;
            }
            back = temp1;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            temp1 = back;
            temp1->next = temp2;
        }
        while (temp2)
        {
            temp2->val = temp2->val + carry;
            carry = 0;
            if (temp2->val > 9)
            {
                temp2->val = temp2->val - 10;
                carry = 1;
            }
            back = temp2;
            temp2 = temp2->next;
        }

        if (carry)
        {
            back->next = new ListNode(1);
        }
        return l1;
    }
};
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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* ptr = head;
        while (ptr->next)
        {
            int a = ptr->val;
            int b = ptr->next->val;
            ListNode* n = ptr->next;
            ListNode* t = new ListNode(__gcd(a, b));
            t->next = n;
            ptr->next = t;
            ptr = n;
        }
        return head;
    }
};
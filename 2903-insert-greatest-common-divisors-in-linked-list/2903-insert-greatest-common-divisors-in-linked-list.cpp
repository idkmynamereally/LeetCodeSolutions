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
            ListNode* t = new ListNode(gcd(a, b));
            t->next = n;
            ptr->next = t;
            ptr = n;
        }
        return head;
    }
    int gcd(int a, int b)
    {
        if (a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        int i = a;
        while (i)
        {
            if (a % i == 0 && b % i == 0)
                return i;
            i--;
        }
        return 0;
    }
};
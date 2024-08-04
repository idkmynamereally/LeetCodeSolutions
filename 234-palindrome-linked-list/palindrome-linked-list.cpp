class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        string s;
        ListNode* temp = head;

        while (temp) {
            s += to_string(temp->val);
            temp = temp->next;
        }

        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
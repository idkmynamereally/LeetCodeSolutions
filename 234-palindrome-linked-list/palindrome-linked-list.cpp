class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> arr;
        ListNode* temp = head;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int l = 0;
        int r = arr.size() - 1;

        while (l < r) {
            if (arr[l++] != arr[r--])
                return false;
        }
        return true;
    }
};
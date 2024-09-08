class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int size = 0;
        ListNode* ptr = head;
        while (ptr)
        {
            size++;
            ptr = ptr->next;
        }

        ptr = head;
        int blockSize = size / k;
        int bigBlocks = size % k;

        if (size < k)
            bigBlocks = 0;
        
        vector<ListNode*> ans(k, nullptr);

        for (int i = 0; ptr && i < k; i++)
        {
            int j = 0;
            ans[i] = ptr;
            for (int j = 0; ptr && j < blockSize - 1; j++)
            {
                ptr = ptr->next;
            }

            if (!ptr)
                break;
            if (bigBlocks)
            {
                ptr = ptr->next;bigBlocks--;
            }

            ListNode* temp = ptr;
            ptr = ptr->next;
            if(temp)
                temp->next = nullptr;
        }

        return ans;
    }
};
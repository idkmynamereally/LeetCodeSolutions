class Solution {
public:
    void printList(ListNode* head)
    {
        ListNode* temp = head;
        while (temp)
        {
            std::cout << temp->val;
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void reorderList(ListNode* head) 
    {
        std::deque<ListNode*> deck;
        ListNode* itr = head;
        while (itr->next != NULL)
        {
            deck.push_back(itr->next);
            itr = itr->next;
        }
        bool frontOrBack{ 1 };
        
        itr = head;
        while (!deck.empty())
        {
            //printList(head);
            if (frontOrBack)    //Get Last Item
            {
                itr->next = deck.back();
                deck.pop_back();
            }
            else    //Get Front Item
            {
                itr->next = deck.front();
                deck.pop_front();
            }
            frontOrBack = !frontOrBack;
            itr = itr->next;
        }
        itr->next = NULL;
    }
};
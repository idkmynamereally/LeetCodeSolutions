class LRUCache
{
public:
    struct LinkedListNode
    {
        std::pair<int, int> val;
        LinkedListNode* next;
        LinkedListNode* prev;
        LinkedListNode(int a, int b) : val(std::pair<int, int>(a, b)), next(nullptr), prev(nullptr)     
        {
            cin.tie(0);
            ios_base::sync_with_stdio(false);
        }
    };


    int capacity{ 0 };
    int count{ 0 };
    LinkedListNode* head{ nullptr };
    LinkedListNode* tail{ nullptr };
    std::unordered_map<int, LinkedListNode*> m;
    LRUCache(int capacity) : capacity(capacity) {}

    void insertFront(LinkedListNode* node)     
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
            head->prev = nullptr;
            head->next = nullptr;
            //return head;
        }
        else
        {
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;
            //return head;
        }
    }

    void insertBack(LinkedListNode* node)     
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
            head->prev = nullptr;
            head->next = nullptr;
            //return head;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            tail = node;
        }
    }

    int deleteFront()      //Returns KEY of the deleted Element
    {
        if (head == NULL)
            return -1;
        int retKey = head->val.first;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        return retKey;
    }

    int deleteBack()
    {
        if (head == NULL)
            return -1;
        int retKey = tail->val.first;
        if (head == tail)
            head = tail = nullptr;
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        return retKey;
    }

    int deleteNodeMiddle(LinkedListNode* node)
    {
        if (head == NULL)
            return -1;
        if (head == tail && head == node)
        {
            head = tail = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        return node->val.first;
    }

    void printCache()
    {
        std::cout << "\n\n<---CACHE--->\n";
        LinkedListNode* temp = head;
        while (temp)
        {
            std::cout << temp->val.first << ", " << temp->val.second << " | ";
            temp = temp->next;
        }
        std::cout << "\n\n";
    }

    int get(int key)
    {
        //printCache();
        //std::cout << "Get : " << key << "\n\n";
        if (!m.contains(key))
            return -1;

        LinkedListNode* node = m[key];

        if (tail == node) 
        {}
        else if (node == head)
        {
            deleteFront();
            insertBack(node);
        }
        else
        {
            deleteNodeMiddle(node);
            insertBack(node);
        }
        //printCache();
        return m[key]->val.second;
    }

    void put(int key, int value)
    {
        //printCache();
        //std::cout << "Put : " << key << "|" << value << "\n";
        if (m.contains(key))        //This is a Node that exists in List no need to update count
        {
            m[key]->val.second = value;
            LinkedListNode* node = m[key];

            if (tail == head)       //1 Node in list
            {
                //do nothing;
            }
            else if (head == node)      //More than 1 node and our node is head
            {
                deleteFront();
                insertBack(node);
            }
            else if (tail == node)      //More than 1 node and our node is last
            {
                //no need to do anything as our node is already MRU.
            }
            else        //Multiple Nodes our Node somewhere in middle
            {
                deleteNodeMiddle(node);
                insertBack(node);
            }
        }
        else        //Node isnt in list right now
        {
            //std::cout << "\nCount, Capcaity : " << count << " " << capacity << "\n";
            LinkedListNode* node = new LinkedListNode(key, value);
            m[key] = node;
            if (count == capacity)
            {
                int deletedKey = deleteFront();
                m.erase(deletedKey);
                insertBack(node);
            }
            else
            {
                insertBack(node);
                count++;
            }
        }
    }
};
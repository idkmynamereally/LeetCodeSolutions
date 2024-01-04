class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        std::unordered_map<Node*, Node*> m;
        Node* temp = head;
        while (temp)
        {
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        Node* newHead = m[head];
        Node* newTemp = m[head];
        while (temp)
        {
            newTemp->next = m[temp->next];
            newTemp->random = m[temp->random];
            temp = temp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};
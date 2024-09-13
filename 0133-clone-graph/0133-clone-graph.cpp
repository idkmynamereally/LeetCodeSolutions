class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        unordered_map<Node *, Node *> mp;
        mp[nullptr] = nullptr;
        clone(node, mp);
        return mp[node];
    }

    void clone(Node *node, unordered_map<Node *, Node *> &mp)
    {
        mp[node] = new Node(node->val);
        Node *currNode = mp[node];

        for (const auto &i : node->neighbors)
        {
            if (!mp.count(i))
                clone(i, mp);
            currNode->neighbors.push_back(mp[i]);
        }
    }
};
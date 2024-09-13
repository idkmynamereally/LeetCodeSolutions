class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<int, Node *> mp;
        return clone(node, mp);
    }

    Node *clone(Node *n, unordered_map<int, Node *> &mp)
    {
        if (!n)
            return nullptr;
        if (mp.count(n->val))
            return mp[n->val];

        mp[n->val] = new Node(n->val);

        for (const auto& i : n->neighbors)
        {
            mp[n->val]->neighbors.push_back(clone(i, mp));
        }
        return mp[n->val];
    }
};
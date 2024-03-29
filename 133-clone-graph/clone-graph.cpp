class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> map;
        dfs(node, map);
        return map[node];
    }

    void dfs(Node* node, unordered_map<Node*, Node*>& map)
    {
        map[node] = new Node(node->val);
        Node* currNode = map[node];

        for (auto n : node->neighbors)
        {
            if (!map.contains(n))
                dfs(n, map);
            currNode->neighbors.push_back(map[n]);
        }
    }
};
class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> map;
        unordered_set<Node*> visited;
        dfs(node, visited, map);
        return map[node];
    }

    void dfs(Node* node, unordered_set<Node*>& visited, unordered_map<Node*, Node*>& map)
    {
        if (visited.contains(node))
            return;
        
        visited.insert(node);

        map[node] = new Node(node->val);
        Node* currNode = map[node];

        for (auto n : node->neighbors)
        {
            dfs(n, visited, map);
            currNode->neighbors.push_back(map[n]);
        }
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        //BFS Time
        std::vector<std::vector<int>> v;
        if (root == nullptr)
            return v;
        std::queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty())
        {
            int ogSize = que.size();
            std::vector<int> currSubList;
            for (int i = 0; i < ogSize; i++)
            {
                TreeNode* temp = que.front();
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
                que.pop();
                currSubList.push_back(temp->val);
            }
            v.push_back(currSubList);
        }
        return v;
    }
};
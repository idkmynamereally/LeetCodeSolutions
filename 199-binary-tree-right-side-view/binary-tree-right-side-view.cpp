class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        //Approach: BFS and only take the last element of each level
        std::vector<int> v;
        if (root == nullptr)
            return v;
        TreeNode* temp = root;
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            int ogSize = que.size();
            for (int i = 0; i < ogSize; i++)
            {
                temp = que.front();
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
                if (i == (ogSize - 1))
                {
                    v.push_back(temp->val);
                }
                que.pop();
            }
        }
        return v;
    }
};
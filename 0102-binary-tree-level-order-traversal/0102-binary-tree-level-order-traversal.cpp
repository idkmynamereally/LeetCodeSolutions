class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        vector<vector<int>> ans;
        
        vector<int> curr;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *top = q.front();
                curr.push_back(top->val);
                
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                
                q.pop();
            }
            ans.push_back(curr);
            curr.clear();
        }
        return ans;
    }
};
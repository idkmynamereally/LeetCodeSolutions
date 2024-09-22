class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        vector<int> ans;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode* top = q.front();
                q.pop();

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                
                if (!size)
                    ans.push_back(top->val);
            }
        }
        return ans;
    }
};
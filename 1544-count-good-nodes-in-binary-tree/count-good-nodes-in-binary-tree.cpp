class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        stack<int> st;
        int ans = 0;
        findMax(root, st, ans);
        return ans;
    }

    void findMax(TreeNode *node, stack<int> &st, int &ans)
    {
        if (!node)
            return;

        if (st.empty())
            st.push(node->val);

        if (node->val >= st.top())
        {
            ans++;
            st.push(node->val);
        }
        findMax(node->left, st, ans);
        findMax(node->right, st, ans);

        if (st.top() == node->val)
            st.pop();
    }
};
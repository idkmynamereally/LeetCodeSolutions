class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        findMax(root, INT_MIN, ans);
        return ans;
    }

    void findMax(TreeNode *node, int max, int &ans)
    {
        if (!node)
            return;

        if (node->val >= max)
        {
            max = node->val;
            ans++;
        }

        findMax(node->left, max, ans);
        findMax(node->right, max, ans);
    }
};
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        trav(root, ans);
        return ans;
    }

    int trav(TreeNode *node, int &ans)
    {
        if (!node)
            return 0;

        int left = max(0, trav(node->left, ans));
        int right = max(0, trav(node->right, ans));

        ans = max(ans, left + right + node->val);

        return node->val + max(left, right);
    }
};
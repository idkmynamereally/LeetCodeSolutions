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

        int left = trav(node->left, ans);
        int right = trav(node->right, ans);

        int t = left + right + node->val;
        t = t > node->val ? t : node->val;
        ans = ans > t ? ans : t;

        int ret = node->val;
        ret += (left > right ? left : right);
        ans = ans > ret ? ans : ret;
        ret = ret > node->val ? ret : node->val;

        return ret;
    }
};
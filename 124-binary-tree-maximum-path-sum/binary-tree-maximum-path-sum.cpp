class Solution 
{
public:
    int maxPathSum(TreeNode* root)
    {
        int ans = INT_MIN;
        solve(ans, root);
        return ans;
    }

    int solve(int& max, TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        int leftMax = solve(max, node->left);
        int rightMax = solve(max, node->right);

        if ((node->val + leftMax + rightMax) > max)
            max = node->val + leftMax + rightMax;

        if ((node->val + leftMax) > max)
            max = node->val + leftMax;

        if ((node->val + rightMax) > max)
            max = node->val + rightMax;

        if (node->val > max)
            max = node->val;

        int ret;
        
        if ((node->val + leftMax) > (node->val + rightMax))
            ret = node->val + leftMax;
        else
            ret = node->val + rightMax;
        
        if (node->val > ret)
            ret = node->val;
        
        return ret;
    }
};
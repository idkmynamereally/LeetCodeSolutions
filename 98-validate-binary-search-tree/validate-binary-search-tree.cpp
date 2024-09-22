#define ll long long
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return recurse(root, (ll)INT_MIN - 2, (ll)INT_MAX + 2);
    }

    bool recurse(TreeNode *node, ll min, ll max)
    {
        if (!node)
            return true;

        int v = node->val;



        if (v <= min || v >= max)
            return false;

        bool ans = true;

        ans &= recurse(node->left, min, v);
        ans &= recurse(node->right, v, max);

        return ans;
    }
};
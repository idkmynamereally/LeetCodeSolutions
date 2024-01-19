class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        long long int mx = (long long int)INT_MAX + 1;
        long long int mn = (long long int)INT_MIN - 1;
        //std::cout << mx;
        return checkBST(mn, mx, root);
    }

    bool checkBST(long long int min, long long int max, TreeNode* node)
    {
        if (node == nullptr)
            return true;
        if (!(node->val > min && node->val < max))
            return false;
        return (checkBST(min, node->val, node->left) && checkBST(node->val, max, node->right));
    }
};
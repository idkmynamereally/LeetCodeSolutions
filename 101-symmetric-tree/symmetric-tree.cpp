class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        return match(root->left, root->right);
    }

    bool match(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
            return true;
        
        if (!left || !right)
            return false;

        if (left->val != right->val)
            return false;

        return match(left->left, right->right) && match(left->right, right->left);
    }
};
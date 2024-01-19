class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        if (!(checkLeftSubTree(root, root->left) && checkRightSubTree(root, root->right)))
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool checkLeftSubTree(TreeNode* ogRoot, TreeNode* node)
    {
        if (node == nullptr)
            return true;
        if (node->val >= ogRoot->val)
            return false;
        return checkLeftSubTree(ogRoot, node->left) && checkLeftSubTree(ogRoot, node->right);
    }
    bool checkRightSubTree(TreeNode* ogRoot, TreeNode* node)
    {
        if (node == nullptr)
            return true;
        if (node->val <= ogRoot->val)
            return false;
        return checkRightSubTree(ogRoot, node->left) && checkRightSubTree(ogRoot, node->right);
    }
};
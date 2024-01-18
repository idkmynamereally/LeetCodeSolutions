class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr)
            return true;

        if (isBalanced(root->left) == false)
            return false;
        if (isBalanced(root->right) == false)
            return false;
        int leftTreeH = depthOfTree(root->left);
        int rightTreeH = depthOfTree(root->right);
        int diff = leftTreeH - rightTreeH;
        if (diff >= -1 && diff <= 1)
            return true;
        return false;
    }

    int depthOfTree(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int leftTree = depthOfTree(root->left);
        int rightTree = depthOfTree(root->right);

        return 1 + (max(leftTree, rightTree));
    }
};
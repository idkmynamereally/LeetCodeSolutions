class Solution 
{
public:
    bool isBalanced(TreeNode* root)     //<Balanced?, Height of subtree> 
    {
        return isNodeBalanced(root).first;
    }

    std::pair<bool, int> isNodeBalanced(TreeNode* node)
    {
        if (node == nullptr)
            return std::pair<bool, int>(true, 0);

        auto leftTree = isNodeBalanced(node->left);
        auto rightTree = isNodeBalanced(node->right);

        int leftH = leftTree.second + 1;
        int rightH = rightTree.second + 1;

        if (leftTree.first && rightTree.first && abs(rightH - leftH) <= 1)
            return std::pair<bool, int>(true, max(leftH, rightH));
        else
            return std::pair<bool, int>(false, max(leftH, rightH));
        return std::pair<bool, int>(false, max(leftH, rightH));
    }
};
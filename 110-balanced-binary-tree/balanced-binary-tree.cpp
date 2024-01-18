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

        /*int leftH = leftTree.second + 1;
        int rightH = rightTree.second + 1;*/

        if (leftTree.first && rightTree.first && abs(rightTree.second + 1 - (leftTree.second + 1)) <= 1)
            return std::pair<bool, int>(true, max(leftTree.second + 1, rightTree.second + 1));
        else
            return std::pair<bool, int>(false, max(leftTree.second + 1, rightTree.second + 1));
        return std::pair<bool, int>(false, max(leftTree.second + 1, rightTree.second + 1));
    }
};
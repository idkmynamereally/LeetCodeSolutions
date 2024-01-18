
class Solution 
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr)
            return false;
        if (isSubtree(root->left, subRoot))
            return true;
        if (isSubtree(root->right, subRoot))
            return true;
        return (isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot) || isSameTree(root, subRoot));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return (inOrder(p,q));
    }

    bool inOrder(TreeNode* node1, TreeNode* node2)
    {
        if (node1 == nullptr || node2 == nullptr)
        {
            return (node1 == node2);
        }
        if (!inOrder(node1->left, node2->left))
            return false;
        if (!inOrder(node1->right, node2->right))
            return false;
        if (node1->val != node2->val)
            return false;
        return true;
    }
};
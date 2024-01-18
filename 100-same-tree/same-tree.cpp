class Solution 
{
public:
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
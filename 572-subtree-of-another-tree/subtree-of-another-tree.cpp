
class Solution 
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr)
            return root == subRoot;
        if (isSubtree(root->left, subRoot))
            return true;
        if (isSubtree(root->right, subRoot))
            return true;
        return isSameTree(root, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (p == nullptr || q == nullptr)
            return (p == q);
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
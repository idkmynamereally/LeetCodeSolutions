class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        return inorder(root, k);
    }

    int inorder(TreeNode *node, int &k)
    {
        if (!node)
            return -1;

        int t1 = inorder(node->left, k);
        k--;
        if (k == 0)
            return node->val;
        int t2 = inorder(node->right, k);

        if (t1 != -1)
            return t1;
        if (t2 != -1)
            return t2;
        return -1;
    }
};
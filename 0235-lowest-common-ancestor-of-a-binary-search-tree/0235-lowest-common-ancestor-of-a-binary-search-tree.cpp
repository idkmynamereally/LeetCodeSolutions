class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return recurse(root, p->val, q->val);
    }

    TreeNode *recurse(TreeNode *node, int val1, int val2)
    {
        int v = node->val;

        if ((val1 > v && val2 < v) || (val1 == v || val2 == v) || (val2 > v && val1 < v))
            return node;

        else if (val1 < v && val2 < v)
            return recurse(node->left, val1, val2);

        else 
            return recurse(node->right, val1, val2);
    }
};
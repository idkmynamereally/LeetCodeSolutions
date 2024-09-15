/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        int t =recurse(root);
        if (t == -1)
            return false;
        return true;
    }

    int recurse(TreeNode* node)
    {
        if (!node)
            return 0;

        int leftDepth = recurse(node->left);
        int rightDepth = recurse(node->right);

        if (leftDepth == -1 || rightDepth == -1)
            return -1;

        if (abs(leftDepth - rightDepth) > 1)
            return -1;

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};
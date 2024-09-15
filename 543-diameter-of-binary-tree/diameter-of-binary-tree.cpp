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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        recurse(root, ans);
        return ans;
    }

    int recurse(TreeNode* root, int& ans)
    {
        if (!root)
            return 0;
        int leftDepth = recurse(root->left, ans);
        int rightDepth = recurse(root->right, ans);

        ans = max(ans, leftDepth + rightDepth);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};
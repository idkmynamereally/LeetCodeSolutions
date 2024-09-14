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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        recurse(ans, root);
        return ans;
    }

    void recurse(vector<int>& ans, TreeNode* root)
    {
        if (!root)
            return;
        recurse(ans, root->left);
        ans.push_back(root->val);
        recurse(ans, root->right);
    }
};
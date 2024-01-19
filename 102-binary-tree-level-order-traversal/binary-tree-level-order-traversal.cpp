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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        std::vector<std::vector<int>> v;
        recLevelOrder(root, 0, v);
        return v;
    }

    void recLevelOrder(TreeNode* root, int level, std::vector<std::vector<int>>& v)
    {
        if (root == nullptr)
            return;
        if (v.size() <= level)
            v.push_back(std::vector<int>());
        v[level].push_back(root->val);
        recLevelOrder(root->left, level + 1, v);
        recLevelOrder(root->right, level + 1, v);
    }
};
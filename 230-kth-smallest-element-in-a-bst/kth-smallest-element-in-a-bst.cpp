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
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        std::vector<int> v;
        inOrder(v, root);
        return v[k - 1];
    }
    void inOrder(std::vector<int>& v, TreeNode* node)
    {
        if (node == nullptr)
            return;
        inOrder(v, node->left);
        v.push_back(node->val);
        inOrder(v, node->right);
    }
};
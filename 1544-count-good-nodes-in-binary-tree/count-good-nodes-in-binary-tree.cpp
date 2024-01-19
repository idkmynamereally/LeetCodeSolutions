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
    int goodNodes(TreeNode* root) 
    {
        int count = 0;
        goodNodesRec(root->val, count, root);
        return count;
    }
    
    void goodNodesRec(int greatestSofar, int& count, TreeNode* node)
    {
        if (node == nullptr)
            return;
        if (node->val >= greatestSofar)
        {
            greatestSofar = node->val;
            count++;
        }
        goodNodesRec(greatestSofar, count, node->left);
        goodNodesRec(greatestSofar, count, node->right);
    }
};
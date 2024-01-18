class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr)
            return nullptr;
        TreeNode* temp = root;
        while (temp)
        {

            if (temp == p || temp == q)
                return temp;
            if (p->val >= temp->val && q->val >= temp->val)
                temp = temp->right;
            else if (p->val < temp->val && q->val < temp->val)
                temp = temp->left;
            else 
                return temp;
        }
        return nullptr;
    }
};
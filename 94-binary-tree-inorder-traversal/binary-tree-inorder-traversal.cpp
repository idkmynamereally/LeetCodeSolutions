class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> nums;
        if (!root)
            return nums;
        TreeNode* temp = root;
        if (root->left)
        {
            auto temp = inorderTraversal(root->left);
            nums.insert(nums.end(), temp.begin(), temp.end());
        }
        nums.push_back(root->val);
        if (root->right)
        {
            auto temp = inorderTraversal(root->right);
            nums.insert(nums.end(), temp.begin(), temp.end());
        }
        return nums;
    }
};
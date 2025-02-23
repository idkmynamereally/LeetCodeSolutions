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
class FindElements {
public:
    unordered_set<int> set;
    FindElements(TreeNode* root) {
        if (!root)
            return;
        root->val = 0;
        set.insert(0);
        findElement(root->left, 0, 0);
        findElement(root->right, 0, 1);
    }

    void findElement(TreeNode* node, int parent, bool right)
    {
        if (!node)
            return;
        node->val = (2 * parent) + 1;
        if (right)
            node->val++;
        set.insert(node->val);
        findElement(node->left, node->val, 0);
        findElement(node->right, node->val, 1);
    }
    
    bool find(int target) {
        return set.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        int rootNodeValue = preorder[0];
        TreeNode* node = new TreeNode(rootNodeValue);
        
        bool leftOrRight = 1;
        std::vector<int> rightPreOrder;
        std::vector<int> rightInOrder;
        std::vector<int> leftPreOrder;
        std::vector<int> leftInOrder;
        for (int i : inorder)
        {
            if (i == rootNodeValue)
            {
                leftOrRight = 0;
                continue;
            }
            if (leftOrRight)
                leftInOrder.push_back(i);
            else
                rightInOrder.push_back(i);
        }

        for (int i = 1; i < preorder.size(); i++)
        {
            if (i <= leftInOrder.size())
                leftPreOrder.push_back(preorder[i]);
            else
                rightPreOrder.push_back(preorder[i]);
        }

        node->left = buildTree(leftPreOrder, leftInOrder);
        node->right = buildTree(rightPreOrder, rightInOrder);
        return node;
    }
};
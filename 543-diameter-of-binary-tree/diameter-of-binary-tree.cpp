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
	int diameterOfBinaryTree(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		int leftSubtreeHeight = depth(root->left, 0);		//add these two if longest path passes throught current node
		int rightSubtreeHeight = depth(root->right, 0);
		int ans = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));	//call same function if the longest path passes through childeren
		ans = max(ans, (leftSubtreeHeight + rightSubtreeHeight));	//if yes then choose the largest of the three.
		return ans;
	}

	int depth(TreeNode* root, int deep)
	{
		if (root == nullptr)
			return deep;
		int leftHeight = depth(root->left, deep+1);
		int rightHeight = depth(root->right, deep+1);
		return (leftHeight > rightHeight ? leftHeight : rightHeight);
	}
};
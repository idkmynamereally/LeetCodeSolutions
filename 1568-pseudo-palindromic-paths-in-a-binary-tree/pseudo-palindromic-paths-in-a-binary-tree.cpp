class Solution
{
public:
    bool isPseudoPalindromic(std::unordered_map<int, int>& map, int count)
    {
        bool oddOccurer{ false };
        if (count % 2 == 0)
            oddOccurer = true;
        for (const auto& i : map)
        {
            if (i.second % 2 != 0)
            {
                if (oddOccurer)
                    return false;
                oddOccurer = 1;
            }
        }
        return true;
    }

    int pseudoPalindromicPaths(TreeNode* root)
    {
        int ans{ 0 };
        std::unordered_map<int, int> map;
        recurse(root, map, 0, ans);
        return ans;
    }

    void recurse(TreeNode* root, std::unordered_map<int, int>& map, int count, int& ans)
    {
        if (!root)
            return;
        
        count++;
        map[root->val]++;

        if (!root->left && !root->right)
        {
            if (isPseudoPalindromic(map, count))
                ans++;
        }
        if (root->left)
            recurse(root->left, map, count, ans);
        if (root->right)
            recurse(root->right, map, count, ans);
        map[root->val]--;
    }
};
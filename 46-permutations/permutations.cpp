class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        std::unordered_set<int> set;
        std::vector<int> curr;
        helper(curr, ans, nums, set);
        return ans;
    }

    void helper(std::vector<int>& curr, std::vector<std::vector<int>>& ans, std::vector<int>& nums, std::unordered_set<int>& set)
    {
        if (curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (set.contains(nums[i]))
                continue;
            curr.push_back(nums[i]);
            set.insert(nums[i]);
            helper(curr, ans, nums, set);
            curr.pop_back();
            set.erase(nums[i]);
        }
    }
};
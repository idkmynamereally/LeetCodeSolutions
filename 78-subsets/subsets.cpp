class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        helper(ans, curr, nums, 0);
        return ans;
    }

    void helper(std::vector<std::vector<int>>& ans, std::vector<int>& curr, std::vector<int>& nums, int indexOfNextItem)
    {
        if (indexOfNextItem == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        helper(ans, curr, nums, indexOfNextItem + 1);
        curr.push_back(nums[indexOfNextItem]);
        helper(ans, curr, nums, indexOfNextItem + 1);
        curr.pop_back();
    }
};
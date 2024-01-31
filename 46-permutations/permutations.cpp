class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        helper(ans, nums, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& nums, int currIndex)
    {
        if (currIndex == nums.size())
        {
            ans.push_back(nums);
        }

        for (int i = currIndex; i < nums.size(); i++)
        {
            std::swap(nums[i], nums[currIndex]);
            helper(ans, nums, currIndex + 1);
            std::swap(nums[i], nums[currIndex]);
        }
    }
};
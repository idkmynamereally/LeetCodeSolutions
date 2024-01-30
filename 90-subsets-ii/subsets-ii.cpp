class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, nums, curr, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& nums, std::vector<int>& curr, int currIndex)
    {
        if (currIndex == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[currIndex]);
        helper(ans, nums, curr, currIndex + 1);
        curr.pop_back();

        while (currIndex < nums.size() - 1 && nums[currIndex] == nums[currIndex + 1])
        {
            currIndex++;
        }
        helper(ans, nums, curr, currIndex + 1);
    }
};
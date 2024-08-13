class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        std::sort(candidates.begin(), candidates.end());
        helper(candidates, ans, curr, 0, 0, target);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, std::vector<int>& curr, int currSum, int currIndex, int target)
    {
        if (currSum == target)
        {
            ans.push_back(curr);
            return;
        }
        
        if (currIndex == nums.size() || currSum > target)
            return;
        
        curr.push_back(nums[currIndex]);
        helper(nums, ans, curr, currSum + nums[currIndex], currIndex + 1, target);
        curr.pop_back();

        currIndex++;
        while (currIndex < nums.size() && nums[currIndex] == nums[currIndex - 1])
            currIndex++;
        helper(nums, ans, curr, currSum, currIndex, target);
    }
};
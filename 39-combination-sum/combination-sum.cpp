class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, candidates, curr, 0, target, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int lastAddedIndex, int target, int currSum)
    {
        if (currSum == target)
        {
            ans.push_back(curr);
            return;
        }
        if (lastAddedIndex == nums.size() || currSum > target)
            return;

        curr.push_back(nums[lastAddedIndex]);
        helper(ans, nums, curr, lastAddedIndex, target, currSum + nums[lastAddedIndex]);
        curr.pop_back();
        helper(ans, nums, curr, lastAddedIndex + 1, target, currSum);
    }
};
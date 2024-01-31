class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, candidates, curr, 0, target, 0);
        return ans;
    }
    
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int currIndex, int target, int currSum)
    {
        if (currSum > target || currIndex >= nums.size())
        {
            return;
        }
        if (currSum == target)
        {
            ans.push_back(curr);
            return;
        }

        helper(ans, nums, curr, currIndex + 1, target, currSum);

        curr.push_back(nums[currIndex]);
        helper(ans, nums, curr, currIndex, target, currSum + nums[currIndex]);
        curr.pop_back();
    }
};
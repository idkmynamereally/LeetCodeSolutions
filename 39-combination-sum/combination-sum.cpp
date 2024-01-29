class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        for (int i = 0; i < candidates.size(); i++)
            helper(ans, candidates, curr, i, target, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int lastAddedIndex, int target, int currSum)
    {
        curr.push_back(nums[lastAddedIndex]);
        currSum += nums[lastAddedIndex];
        if (currSum == target)
        {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        for (int i = lastAddedIndex; i < nums.size(); i++)
        {
            if (currSum + nums[i] > target)
                continue;
            helper(ans, nums, curr, i, target, currSum);
        }
        curr.pop_back();
    }
};
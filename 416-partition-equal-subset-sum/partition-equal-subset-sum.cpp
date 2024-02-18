class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum{ 0 };
        for (int i : nums)
            sum += i;

        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1)); 
        return recurse(nums, 0, sum / 2, dp);
    }

    bool recurse(vector<int>& nums, int currIndex, int target, vector<vector<int>>& dp)
    {
        if (target < 0)
            return false;
        
        if (target == 0)
            return true;

        if (currIndex == nums.size())
            return false;

        if (dp[currIndex][target] != -1)
            return dp[currIndex][target];

        if (recurse(nums, currIndex + 1, target - nums[currIndex], dp))
        {
            dp[currIndex][target] = true;
            return true;
        }
        if (recurse(nums, currIndex + 1, target, dp))
        {
            dp[currIndex][target] = true;
            return true;
        }
        return dp[currIndex][target] = false;
    }
};
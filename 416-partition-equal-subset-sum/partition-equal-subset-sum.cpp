class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2)
            return false;

        int target = sum/2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, false));

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < target; j++)
            {
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int t = 1; t <= target; t++)
            {
                if (t - nums[i] >= 0)
                    dp[i][t] |= dp[i + 1][t - nums[i]];
                dp[i][t] |= dp[i + 1][t];
            }
        }
        return dp[0][target];
    }

    bool recurse(vector<int>& nums, int i, int target, vector<vector<int>>& dp)
    {
        if (target == 0)
            return true;
        if (i == nums.size())
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        dp[i][target] = false;

        if (target - nums[i] >= 0)
            dp[i][target] = recurse(nums, i + 1, target - nums[i], dp);
        dp[i][target] |= recurse(nums, i + 1, target, dp);
        
        return dp[i][target];
    }
};
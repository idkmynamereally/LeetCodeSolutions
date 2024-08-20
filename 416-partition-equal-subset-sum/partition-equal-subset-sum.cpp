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

        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));

        return recurse(nums, 0, target, dp);
    }

    bool recurse(vector<int>& nums, int i, int target, vector<vector<int>>& dp)
    {
        if (target == 0)
            return true;
        if (i == nums.size())
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        int take = false;
        int leave = false;
        if (target - nums[i] >= 0)
            take = recurse(nums, i + 1, target - nums[i], dp);
        leave = recurse(nums, i + 1, target, dp);

        dp[i][target] = take || leave;
        return dp[i][target];
    }
};
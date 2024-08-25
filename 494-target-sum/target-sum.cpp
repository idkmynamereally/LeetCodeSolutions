class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int s1 = (target + sum) / 2;
        if (sum % 2 && !(target % 2))
            return 0;
        if (!(sum % 2) && target % 2)
            return 0;

        if (s1 < 0)
            s1 = sum - s1;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(s1 + 1, -1));

        return recurse(nums, 0, s1, dp);
    }

    int recurse(vector<int> &nums, int i, int t, vector<vector<int>> &dp)
    {
        if (i == nums.size() && t == 0)
            return 1;
        if (i == nums.size() || t < 0)
            return 0;

        if (dp[i][t] != -1)
            return dp[i][t];

        int take = recurse(nums, i + 1, t - nums[i], dp);
        int leave = recurse(nums, i + 1, t, dp);

        dp[i][t] = take + leave;
        return dp[i][t];
    }
};
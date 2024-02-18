class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        unordered_map<int, int> dp;
        int ans = recurse(coins, amount, dp);
        ans = (ans == INT_MAX) ? -1 : ans;
        return ans;
    }

    int recurse(vector<int>& nums, int target, unordered_map<int, int>& dp)
    {
        if (dp.contains(target))
            return dp[target];
        if (target == 0)
            return 0;
        if (target < 0)
            return INT_MAX;

        int min = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int ans = recurse(nums, target - nums[i], dp);
            if (ans != INT_MAX)
            {
                ans++;
                min = min < ans ? min : ans;
            }
        }
        dp[target] = min;
        return min;
    }
};
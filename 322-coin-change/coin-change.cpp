class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            int ans = INT_MAX;
            for (int coin : coins)
            {
                if (i - coin < 0)
                    continue;
                if (dp[i - coin] == INT_MAX)
                    continue;
                ans = dp[i - coin] + 1;
                dp[i] = ans < dp[i] ? ans : dp[i];
            }
        }
        
        if (dp[amount] == INT_MAX)
            return -1;

        return dp[amount];
    }
};
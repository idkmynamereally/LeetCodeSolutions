class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // ---------recursion---------
        // return recurse(coins, amount, 0);

        // --------memoization--------
        // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        // return recurse(coins, amount, 0, dp);

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= coins.size(); i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                if (i == coins.size())
                    dp[i][t] = 0; // 0 possible subsets if no more coins left
                if (t == 0)
                    dp[i][t] = 1; // 1 possible subset if amount to make is 0
            }
        }

        for (int i = coins.size() - 1; i >= 0; i--)
        {
            for (int t = 1; t <= amount; t++)
            {
                if (t - coins[i] >= 0)
                    dp[i][t] = dp[i][t - coins[i]];
                dp[i][t] += dp[i + 1][t];
            }
        }

        return dp[0][amount];
    }

    int recurse(vector<int> &coins, int t, int i, vector<vector<int>> &dp)
    {
        if (i == coins.size() || t < 0)
            return 0;
        if (t == 0)
            return 1;

        if (dp[i][t] != -1)
            return dp[i][t];

        int take = recurse(coins, t - coins[i], i, dp);
        int leave = recurse(coins, t, i + 1, dp);

        dp[i][t] = take + leave;
        return dp[i][t];
    }
};
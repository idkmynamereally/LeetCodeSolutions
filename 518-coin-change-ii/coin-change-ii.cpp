class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // recursion
        // return recurse(coins, amount, 0);

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return recurse(coins, amount, 0, dp);
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
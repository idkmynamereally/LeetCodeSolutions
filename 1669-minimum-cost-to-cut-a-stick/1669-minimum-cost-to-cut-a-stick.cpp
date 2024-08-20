class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        unordered_map<int, unordered_map<int, int>> dp;
        return recurse(cuts, 0, n, dp);
    }

    int recurse(vector<int> &cuts, int i, int j, unordered_map<int, unordered_map<int, int>>& dp)
    {
        if (i >= j - 1)
            return 0;

        if (dp.count(i))
        {
            if (dp[i].count(j))
                return dp[i][j];
        }

        int ans = INT_MAX;
        for (int k : cuts)
        {
            if (k <= i || k >= j)
                continue;
            ans = min(ans, (j - i) + recurse(cuts, i, k, dp) + recurse(cuts, k, j, dp));
        }

        if (ans == INT_MAX)
            dp[i][j] = 0;
        else
            dp[i][j] = ans;
        return dp[i][j];
    }
};
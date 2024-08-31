#define sv string_view

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return recurse(s, t, 0, 0, dp);
    }

    int recurse(sv s, sv t, int i, int j, vector<vector<int>> &dp)
    {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        int leave = 0;
        if (s[i] == t[j])
        {
            take = recurse(s, t, i + 1, j + 1, dp);
            leave = recurse(s, t, i + 1, j, dp);
        }
        else
        {
            leave = recurse(s, t, i + 1, j, dp);
        }

        dp[i][j] = take + leave;
        return dp[i][j];
    }
};
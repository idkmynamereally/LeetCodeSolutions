#define sv string_view

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return recurse(s, p, 0, 0, dp);
    }

    bool recurse(sv s, sv p, int i, int j, vector<vector<int>> &dp)
    {
        bool ans = false;

        if (i == s.size() && j == p.size())
            return true;

        if (j == p.size())
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s.size())
        {
            if (j == p.size() - 1)
                return false;
            if (p[j + 1] == '*')
                dp[i][j] = recurse(s, p, i, j + 2, dp);
            else
                dp[i][j] = false;
            return dp[i][j];
        }

        if (p[j + 1] == '*')
        {
            if (s[i] == p[j] || p[j] == '.')
            {
                ans |= recurse(s, p, i + 1, j, dp); // More occur of curr char
            }
            ans |= recurse(s, p, i, j + 2, dp); // Matched all we can
        }

        else if (s[i] == p[j] || p[j] == '.')
        {
            ans |= recurse(s, p, i + 1, j + 1, dp);
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
};
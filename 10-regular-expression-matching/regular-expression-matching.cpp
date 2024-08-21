class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return recurse(s, p, 0, 0, dp);
    }

    bool recurse(string_view s, string_view p, int i, int j, vector<vector<int>> &dp)
    {
        if (i == s.size() && j == p.size())
            return true;
        if (i == s.size())
        {
            int left = p.size() - j;
            if (left % 2)
                return false;
            j += 1;
            while (j < p.size() && p[j] == '*')
                j += 2;
            if (j < p.size())
                return false;
            return true;
        }
        if (j >= p.size())
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (j + 1 != p.size() && p[j + 1] == '*')
        {
            bool ans = false;
            if (s[i] == p[j] || p[j] == '.')
            {
                ans |= recurse(s, p, i + 1, j, dp);
                ans |= recurse(s, p, i + 1, j + 2, dp);
            }
            ans |= recurse(s, p, i, j + 2, dp);
            dp[i][j] = ans;
            return ans;
        }
        else
        {
            if (s[i] == p[j] || p[j] == '.')
                dp[i][j] = recurse(s, p, i + 1, j + 1,dp);
            else
                dp[i][j] = false;

            return dp[i][j];
        }
        dp[i][j] = false;
        return dp[i][j];
    };
};
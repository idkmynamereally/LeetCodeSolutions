#define MOD 1000000007
#define ll long long
#define sv string_view

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return match(s1, s2, s3, 0, 0, dp);
    }

    bool match(sv s1, sv s2, sv s3, int i, int j, vector<vector<int>> &dp)
    {
        int ptr = i + j;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (ptr == s3.size())
            return true;
        if (s1[i] == s2[j] && s1[i] == s3[ptr])
        {
            bool ans = false;
            ans |= match(s1, s2, s3, i + 1, j, dp);
            ans |= match(s1, s2, s3, i, j + 1, dp);
            dp[i][j] = ans;
            return ans;
        }

        if (i < s1.size() && s1[i] == s3[ptr])
            dp[i][j] = match(s1, s2, s3, i + 1, j, dp);
        else if (j < s2.size() && s2[j] == s3[ptr])
            dp[i][j] = match(s1, s2, s3, i, j + 1, dp);
        else
            dp[i][j] = false;
        return dp[i][j];
    }
};
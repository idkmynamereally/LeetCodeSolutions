#define sv string_view

class Solution
{
public:
    int minDistance(string s1, string s2)
    {
        //vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        //return recurse(s1, s2, 0, 0, dp);

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, INT_MAX));

        for (int i = 0; i <= s1.size(); i++)
        {
            for (int j = 0; j <= s2.size(); j++)
            {
                if (i == s1.size())
                    dp[i][j] = s2.size() - j;
                if (j == s2.size())
                    dp[i][j] = s1.size() - i;
            }
        }

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                int match = INT_MAX;
                int replace = INT_MAX;
                int del = INT_MAX;
                int insert = INT_MAX;

                if (s1[i] == s2[j])
                    match = dp[i + 1][j + 1];
                else
                    replace = 1 + dp[i + 1][j + 1];
                del = 1 + dp[i + 1][j];
                insert = 1 + dp[i][j + 1];

                dp[i][j] = min(match, min(replace, min(del, insert)));
            }
        }

        return dp[0][0];
    }

    int recurse(sv s1, sv s2, int i, int j, vector<vector<int>>& dp)
    {
        if (j == s2.size())
            return s1.size() - i;
        if (i == s1.size())
            return s2.size() - j;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int match = INT_MAX;
        int replace = INT_MAX;
        int del = INT_MAX;
        int insert = INT_MAX;

        del = 1 + recurse(s1, s2, i + 1, j, dp);
        insert = 1 + recurse(s1, s2, i, j + 1, dp);
        
        if (s1[i] == s2[j])
        {
            match = 0 + recurse(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            replace = 1 + recurse(s1, s2, i + 1, j + 1, dp);
        }

        dp[i][j] = min(match, min(replace, min(del, insert)));
        return dp[i][j];
    }
};
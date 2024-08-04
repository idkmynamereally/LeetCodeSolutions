class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));     //store answers to different i,j combos.

        int ans = recurse(text1, text2, dp, 0, 0);
        return ans;
    }

    int recurse(string_view t1, string_view t2, vector<vector<int>>& dp, int i, int j) {
        if (i == t1.size() || j == t2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (t1[i] == t2[j]) {
            dp[i][j] = 1 + recurse(t1, t2, dp, i + 1, j + 1);
        }
        else
        {
            int a1 = recurse(t1, t2, dp, i, j + 1);
            int a2 = recurse(t1, t2, dp, i + 1, j);
            dp[i][j] = max(a1, a2);
        }

        return dp[i][j];
    }
};
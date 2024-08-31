class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int ans = 0;
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, -1));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int t = recurse(matrix, i, j, dp);
                ans = ans > t ? ans : t;
            }
        }
        return ans;
    }

    int recurse(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (i == matrix.size() || j == matrix[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int max = 0;

        if (j != matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j])
        {
            int t = recurse(matrix, i, j + 1, dp);
            max = max > t ? max : t;
        }
        if (j != 0 && matrix[i][j - 1] > matrix[i][j])
        {
            int t = recurse(matrix, i, j - 1, dp);
            max = max > t ? max : t;
        }
        if (i != matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j])
        {
            int t = recurse(matrix, i + 1, j, dp);
            max = max > t ? max : t;
        }
        if (i != 0 && matrix[i - 1][j] > matrix[i][j])
        {
            int t = recurse(matrix, i - 1, j, dp);
            max = max > t ? max : t;
        }
        dp[i][j] = 1 + max;
        return dp[i][j];
    }
};
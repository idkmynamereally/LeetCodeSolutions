class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int> (n));

        for (int i = m - 1; i >= 0; i--)
        {
            paths[i][n - 1] = 1;
        }

        for (int j = n - 1; j >= 0; j--)
        {
            paths[m - 1][j] = 1;
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                paths[i][j] = paths[i + 1][j] + paths[i][j + 1];
            }
        }

        return paths[0][0];
    }
};
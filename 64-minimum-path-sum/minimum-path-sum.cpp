class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        //vector<vector<int>> dp(r, vector<int>(c, 0));

        for (int i = 1; i < c; i++)
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        for (int i = 1; i < r; i++)
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                int a = grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
                grid[i][j] += a;
            }
        }
        return grid[r - 1][c - 1];
    }
};
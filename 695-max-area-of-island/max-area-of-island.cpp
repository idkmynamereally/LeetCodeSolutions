class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    int t = dfs(grid, i, j);
                    ans = ans > t ? ans : t;
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j])
            return 0;

        grid[i][j] = 0;
        int ret = 1;

        ret += dfs(grid, i + 1, j);
        ret += dfs(grid, i - 1, j);
        ret += dfs(grid, i, j + 1);
        ret += dfs(grid, i, j - 1);


        return ret;
    }
};
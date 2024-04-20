class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> ans(r, vector<int>(c, INT_MAX));
        recurse(0, 0, 0, grid, ans);

        return ans[r - 1][c - 1];
    }

    void recurse(int r, int c, int dist, vector<vector<int>>& grid, vector<vector<int>>& ans)
    {
        if (r < 0 || r >= grid.size())
            return;
        if (c < 0 || c >= grid[0].size())
            return;

        if ((dist + grid[r][c]) < ans[r][c])
            ans[r][c] = dist + grid[r][c];
        else
            return;

        recurse(r + 1, c, ans[r][c], grid, ans);
        recurse(r, c + 1, ans[r][c], grid, ans);
    }
};
// Boost i/o.
auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (r == -1 || c == -1 || r >= grid.size() || c >= grid[0].size())
            return;
        if (grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
    }
};
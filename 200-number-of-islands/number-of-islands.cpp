class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> col(n, false);
        vector<vector<bool>> visited(grid.size(), col);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c)
    {
        if (r == -1 || c == -1 || r >= grid.size() || c >= grid[0].size())
            return;
        if (visited[r][c] == true)
            return;
        if (grid[r][c] == '0')
            return;
        visited[r][c] = true;
        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c - 1);
    }
};
class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(pair<int, int>(i, j));
                }
            }
        }
        int ans = bfs(grid, q);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q)
    {
        if (q.empty())
            return 0;
        int ans = -1;
        while (!q.empty())
        {
            ans++;
            int size = q.size();
            while (size--)
            {
                auto top = q.front();
                int r = top.first;
                int c = top.second;
                if (c < grid[0].size() - 1 && grid[r][c + 1] == 1)
                {
                    grid[r][c + 1] = 2;
                    q.push(pair<int, int>(r, c + 1));
                }
                if (c != 0 && grid[r][c - 1] == 1)
                {
                    grid[r][c - 1] = 2;
                    q.push(pair<int, int>(r, c - 1));
                }
                if (r != 0 && grid[r - 1][c] == 1)
                {
                    grid[r - 1][c] = 2;
                    q.push(pair<int, int>(r - 1, c));
                }
                if (r < grid.size() - 1 && grid[r + 1][c] == 1)
                {
                    grid[r + 1][c] = 2;
                    q.push(pair<int, int>(r + 1, c));
                }
                q.pop();
            }
        }
        return ans;
    }
};
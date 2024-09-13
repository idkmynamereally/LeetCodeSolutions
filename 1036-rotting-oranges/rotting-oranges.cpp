class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push(pair<int, int>(i, j));
            }
        }

        int t = bfs(grid, q);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return t;
    }

    int bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q)
    {
        int mint = -1; // minutes passed;
        while (!q.empty())
        {
            mint++;
            int size = q.size(); // number of rotten oranges in current level
            while (size--)
            {
                auto front = q.front();
                q.pop();
                int r = front.first;
                int c = front.second;
                if ((r - 1) >= 0 && grid[r - 1][c] == 1)
                {
                    grid[r - 1][c] = 2;
                    q.push(pair<int, int>(r - 1, c));
                }

                if ((r + 1) != grid.size() && grid[r + 1][c] == 1)
                {
                    grid[r + 1][c] = 2;
                    q.push(pair<int, int>(r + 1, c));
                }

                if ((c + 1) != grid[0].size() && grid[r][c + 1] == 1)
                {
                    grid[r][c + 1] = 2;
                    q.push(pair<int, int>(r, c + 1));
                }

                if ((c - 1) >= 0 && grid[r][c - 1] == 1)
                {
                    grid[r][c - 1] = 2;
                    q.push(pair<int, int>(r, c - 1));
                }
            }
        }
        if (mint == -1)
            return 0;
        return mint;
    }
};
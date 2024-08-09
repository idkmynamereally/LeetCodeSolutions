class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        if (grid.size() < 3 && grid[0].size() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i < grid.size() - 2; i++)
        {
            for (int j = 0; j < grid[0].size() - 2; j++)
            {
                if (isMagicSquare(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }

    bool isMagicSquare(vector<vector<int>>& grid, int r, int c)
    {
        vector<bool> set(10, false);
        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {
                if (grid[i][j] > 9 || grid[i][j] == 0)
                    return false;

                if (set[grid[i][j]])
                    return false;
                set[grid[i][j]] = true;
            }
        }

        int sum = 0;

        for (int i = r; i < r + 3; i++)
        {
            sum += grid[i][c];
        }

        int t;
        for (int i = r + 1; i < r + 3; i++)
        {
            t = 0;
            for (int j = c; j < c + 3; j++)
                t += grid[i][j];

            if (t != sum)
                return false;
        }

        for (int j = c; j < c + 3; j++)
        {
            t = 0;
            for (int i = r; i < r + 3; i++)
                t += grid[i][j];

            if (t != sum)
                return false;
        }

        if (t != sum)
            return false;

        t = 0;
        t = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];

        if (t != sum)
            return false;

        t = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        if (t != sum)
            return false;

        return true;
    }
};
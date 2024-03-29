class Solution 
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int temp = maxArea(i, j, grid);
                    ans = ans > temp ? ans : temp;
                }
            }
        }
        return ans;
    }

    int maxArea(int r, int c, vector<vector<int>>& grid)
    {
        if (r == grid.size() || r == -1 || c == -1 || c == grid[0].size())
            return 0;

        if (grid[r][c] == 0)
            return 0;

        int area = 1;
        grid[r][c] = 0;

        area += maxArea(r, c - 1, grid);
        area += maxArea(r + 1, c, grid);
        area += maxArea(r, c + 1, grid);
        area += maxArea(r - 1, c, grid);


        return area;
    }
};
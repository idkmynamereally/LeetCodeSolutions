class Solution 
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>> ans;
        vector<vector<bool>> pac(heights.size(), vector<bool>(heights[0].size()));
        vector<vector<bool>> atl(heights.size(), vector<bool>(heights[0].size()));
        
        for (int i = 0; i < heights.size(); i++)
        {
            dfs(i, 0, heights, pac);

            dfs(i, heights[0].size() - 1, heights, atl);
        }

        for (int i = 0; i < heights[0].size(); i++)
        {
            dfs(0, i, heights, pac);

            dfs(heights.size() - 1, i, heights, atl);
        }

        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                if (pac[i][j] && atl[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited)
    {
        if (visited[r][c] == true)
            return;
        visited[r][c] = true;

        if ((r - 1) >= 0 && heights[r - 1][c] >= heights[r][c])
            dfs(r - 1, c, heights, visited);
        if ((r + 1) < heights.size() && heights[r + 1][c] >= heights[r][c])
            dfs(r + 1, c, heights, visited);
        if ((c - 1) >= 0 && heights[r][c - 1] >= heights[r][c])
            dfs(r, c - 1, heights, visited);
        if ((c + 1) < heights[0].size() && heights[r][c + 1] >= heights[r][c])
            dfs(r, c + 1, heights, visited);
    }
};
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = i - 0;
                int down = n - i - 1;
                int left = j - 0;
                int right = n - j - 1;
                ans[i][j] = min(min(min(up, down), right), left) + 1;
            }
        }

        for (auto mine : mines)
        {
            int r = mine[0];
            int c = mine[1];
            ans[r][c] = 0;
            int put = 1;
            for (int i = r - 1; i >= 0; i--)
            {
                ans[i][c] = ans[i][c] > put ? put : ans[i][c];
                put++;
            }
            put = 1;
            for (int i = r + 1; i < n; i++)
            {
                ans[i][c] = ans[i][c] > put ? put : ans[i][c];
                put++;
            }
            put = 1;
            for (int j = c - 1; j >= 0; j--)
            {
                ans[r][j] = ans[r][j] > put ? put : ans[r][j];
                put++;
            }
            put = 1;
            for (int j = c + 1; j < n; j++)
            {
                ans[r][j] = ans[r][j] > put ? put : ans[r][j];
                put++;
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                max = max > ans[i][j] ? max : ans[i][j];
        }

        return max;
    }
};
const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 1));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                ans[i][j] = matrix[i][j] - '0';
        }

        int a = r - 2;
        int b = c - 2;
        for (; a >= 0 && b >= 0; a--, b--)
        {
            for (int i = a; i >= 0; i--)
            {
                if (ans[i][b] == 0)
                    continue;
                int right = ans[i][b + 1];
                int down = ans[i + 1][b];
                int diag = ans[i + 1][b + 1];
                ans[i][b] = min(min(right, down), diag) + 1;
            }
            for (int j = b; j >= 0; j--)
            {
                if (ans[a][j] == 0)
                    continue;
                int right = ans[a + 1][j];
                int down = ans[a][j + 1];
                int diag = ans[a + 1][j + 1];
                ans[a][j] = min(min(right, down), diag) + 1;
            }
        }
        int max = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                max = max > ans[i][j] ? max : ans[i][j];
            }
        }

        if (max > 1)
            return ceil(pow(max, 2));
        return max;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int size = matrix.size();
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                int ans = INT_MAX;
                ans = min(ans, matrix[i][j] + matrix[i - 1][j]);
                if (j - 1 >= 0)
                    ans = min(ans, matrix[i][j] + matrix[i - 1][j - 1]);
                if (j + 1 < matrix.size())
                    ans = min(ans, matrix[i][j] + matrix[i - 1][j + 1]);

                matrix[i][j] = ans;
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < matrix.size(); j++){
            ans = ans < matrix[size - 1][j] ? ans : matrix[size - 1][j];
        }

        return ans;
    }
};
// i-1, j | i-1, j-1 | i-1, j+1
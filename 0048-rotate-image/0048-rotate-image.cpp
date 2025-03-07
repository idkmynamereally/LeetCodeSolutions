class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int t = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = t;
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
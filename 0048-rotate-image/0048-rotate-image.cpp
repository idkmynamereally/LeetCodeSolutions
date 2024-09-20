class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++) // transpose of matrix
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    break;
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }

        for (int i = 0; i < n; i++) // reverse all rows
        {
            int l = 0;
            int r = n - 1;

            while (l < r)
            {
                int t = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = t;
                l++;
                r--;
            }
        }
    }
};
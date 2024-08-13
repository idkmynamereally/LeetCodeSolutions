class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int size = matrix.size();
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        for (int j = 0; j < matrix[0].size(); j++)
            visited[0][j] = true;

        int ans = INT_MAX;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            ans = min(ans, recurse(matrix, matrix.size() - 1, j, visited));
        }

        return ans;
    }

    int recurse(vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& visited)
    {
        if (i >= mat.size() || i < 0 || j >= mat[0].size() || j < 0)
            return INT_MAX;

        if (visited[i][j])
            return mat[i][j];

        int minUp = INT_MAX;
        
        minUp = min(minUp, recurse(mat, i - 1, j, visited));
        minUp = min(minUp, recurse(mat, i - 1, j - 1, visited));
        minUp = min(minUp, recurse(mat, i - 1, j + 1, visited));

        visited[i][j] = true;
        mat[i][j] = minUp + mat[i][j];

        return mat[i][j];
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<int> cols;
        unordered_set<int> rows;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (!matrix[i][j])
                {
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (cols.contains(j) || rows.contains(i))
                    matrix[i][j] = 0;
            }
        }
    }
};
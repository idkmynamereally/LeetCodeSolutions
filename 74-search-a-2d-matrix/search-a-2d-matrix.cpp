class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        int row{};
        int rowLeft{ 0 };
        int rowRight = matrix.size()-1;
        int rowMiddle{};

        while (rowLeft <= rowRight)
        {
            rowMiddle = rowLeft + floor((rowRight - rowLeft)/2);

            if (target >= matrix[rowMiddle][0] && target <= matrix[rowMiddle][matrix[rowMiddle].size() - 1])
            {
                row = rowMiddle;
                break;
            }
            else if (target < matrix[rowMiddle][0])
            {
                rowRight = rowMiddle - 1;
            }
            else if (target > matrix[rowMiddle][matrix[rowMiddle].size() - 1])
            {
                rowLeft = rowMiddle + 1;
            }
        }

        if (target > matrix[row][matrix[row].size() - 1])
            return false;

        int colLeft{ 0 };
        int colRight = matrix[row].size() - 1;
        int colMiddle{};

        while (colLeft <= colRight)
        {
            colMiddle = colLeft + floor((colRight - colLeft) / 2);
            if (matrix[row][colMiddle] == target)
                return true;
            else if (matrix[row][colMiddle] < target)
                colLeft = colMiddle + 1;
            else if (matrix[row][colMiddle] > target)
                colRight = colMiddle - 1;
        }
        return false;
    }
};
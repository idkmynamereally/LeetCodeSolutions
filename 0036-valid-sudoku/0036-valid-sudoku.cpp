class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        std::vector<std::set<char>> rows(9);
        std::vector<std::set<char>> cols(9);
        std::vector<std::set<char>> squares(9);

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                char value = board[r][c];
                if (value == '.')
                    continue;

                if (rows[r].contains(value) || cols[c].contains(value) || squares[(r / 3) * 3 + (c / 3)].contains(value))
                {
                    return false;
                }
                else
                {
                    rows[r].insert(value);
                    cols[c].insert(value);
                    squares[(r / 3) * 3 + (c / 3)].insert(value);
                }
            }
        }
        return true;
    }
};
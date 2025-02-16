class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowset(9);
        vector<unordered_set<char>> colset(9);
        
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_set<char> box;
                for (int r = i; r < i + 3; r++)
                {
                    for (int c = j; c < j + 3; c++)
                    {
                        if (board[r][c] == '.')
                            continue;

                        if (rowset[r].contains(board[r][c]))
                            return false;
                        rowset[r].insert(board[r][c]);

                        if (colset[c].contains(board[r][c]))
                            return false;
                        colset[c].insert(board[r][c]);

                        if (box.contains(board[r][c]))
                            return false;
                        box.insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};
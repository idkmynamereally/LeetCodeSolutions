class Solution
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string row;
        for (int i = 0; i < n; i++)
        {
            row.push_back('.');
        }
        vector<string> board;
        for (int i = 0; i < n; i++)
        {
            board.push_back(row);
        }
        solve(ans, board, 0, n);
        return ans;
    }

    void solve(vector<vector<string>>& ans, vector<string>& board, int currRow, int n)
    {
        if (currRow == n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            board[currRow][col] = 'Q';
            //std::cout << "\n";
            //printBoard(board, n);
            if (checkBoard(board, currRow, col, n))
                solve(ans, board, currRow + 1, n);
            board[currRow][col] = '.';
        }
    }

    void printBoard(vector<string>& board, int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << board[i] << "\n";
        }
    }

    bool checkBoard(vector<string>& board, int currRow, int currCol, int n)
    {
        for (int row = currRow + 1; row < n; row++)
        {
            if ((board[row])[currCol] == 'Q')
                return false;
        }
        for (int row = currRow - 1; row >= 0; row--)
        {
            if ((board[row])[currCol] == 'Q')
                return false;
        }
        for (int row = currRow - 1, col = currCol - 1; row >= 0 && col >= 0; row--,col--)
        {
            if (board[row][col] == 'Q')
                return false;
        }
        for (int row = currRow + 1, col = currCol + 1; row < n && col < n; row++, col++)
        {
            if (board[row][col] == 'Q')
                return false;
        }
        for (int row = currRow - 1, col = currCol + 1; row >= 0 && col < n; row--, col++)
        {
            if (board[row][col] == 'Q')
                return false;
        }
        for (int row = currRow + 1, col = currCol - 1; row < n && col >= 0; row++, col--)
        {
            if (board[row][col] == 'Q')
                return false;
        }
        return true;
    }
};
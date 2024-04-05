class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        vector<vector<bool>> flip(board.size(), vector<bool>(board[0].size(), true));
        for (int i = 0; i < board.size(); i++)
        {
            dfs(i, 0, board, flip);

            dfs(i, board[0].size() - 1, board, flip);
        }

        for (int i = 0; i < board[0].size(); i++)
        {
            dfs(0, i, board, flip);

            dfs(board.size() -1, i, board, flip);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (flip[i][j])
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& flip)
    {
        if (r < 0 || r == board.size() || c < 0 || c == board[0].size())
            return;
        if (board[r][c] == 'X')
            return;
        if (flip[r][c] == false)
            return;
        flip[r][c] = false;

        dfs(r - 1, c, board, flip);
        dfs(r + 1, c, board, flip);
        dfs(r, c + 1, board, flip);
        dfs(r, c - 1, board, flip);
    }
};
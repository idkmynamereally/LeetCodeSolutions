class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        bool ans = false;
        pair<int, int> curr(0, 0);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                curr.first = i;
                curr.second = j;
                ans = makePath(board, curr, word, 0);
                if (ans == true)
                    return ans;
            }
        }
        return ans;
    }

    bool makePath(vector<vector<char>>& board, pair<int, int> curr, string_view word, int charIndex)
    {
        if (charIndex == word.size())
            return true;

        int leftLimit = 0;
        int upLimit = 0;
        int rightLimit = board[0].size();
        int downLimit = board.size();

        int row = curr.first;
        int col = curr.second;
        if (row < upLimit || row >= downLimit)
            return false;
        if (col < leftLimit || col >= rightLimit)
            return false;

        bool left = false;
        bool right = false;
        bool up = false;
        bool down = false;

        char temp = board[row][col];
        if (board[row][col] == word[charIndex])
        {
            board[row][col] = '!';
            left = makePath(board, pair<int, int>(row, col - 1), word, charIndex + 1);
            up = makePath(board, pair<int, int>(row - 1, col), word, charIndex + 1);
            right = makePath(board, pair<int, int>(row, col + 1), word, charIndex + 1);
            down = makePath(board, pair<int, int>(row + 1, col), word, charIndex + 1);
            board[row][col] = temp;
        }
        return left || up || right || down;
    }
};
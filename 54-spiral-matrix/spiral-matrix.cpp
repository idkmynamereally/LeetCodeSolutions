class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int r = matrix.size();
        int c = matrix[0].size();

        int t = r * c;
        int i = 0;
        int j = 0;

        int rlimit = c;
        int dlimit = r;
        int llimit = -1;
        int ulimit = 0;

        while (t)
        {
            for (; t && j < rlimit; j++)
            {
                ans.push_back(matrix[i][j]);
                t--;
            }
            j--;
            i++;
            rlimit--;
            for (; t && i < dlimit; i++)
            {
                ans.push_back(matrix[i][j]);
                t--;
            }
            i--;
            j--;
            dlimit--;
            for (; t && j > llimit; j--)
            {
                ans.push_back(matrix[i][j]);
                t--;
            }
            j++;
            i--;
            llimit++;
            for (; t && i > ulimit; i--)
            {
                ans.push_back(matrix[i][j]);
                t--;
            }
            i++;
            j++;
            ulimit++;
        }
        return ans;
    }
};
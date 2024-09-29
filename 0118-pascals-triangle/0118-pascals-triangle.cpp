int speedUp = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        if (!numRows)
            return ans;
        
        ans[0].push_back(1);
        for (int i = 1; i < numRows; i++)
        {
            ans[i].resize(i + 1);
            for (int j = 0; j < ans[i].size(); j++)
            {
                int t = 0;
                if (j < ans[i - 1].size())
                    t += ans[i - 1][j];
                if (j - 1 >= 0)
                    t += ans[i - 1][j - 1];
                ans[i][j] = t; 
            }
        }
        return ans;
    }
};
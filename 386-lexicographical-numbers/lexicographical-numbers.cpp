class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for (int i = 1; i < 10; i++)
            dfs(n, i, ans);
        return ans;
    }

    void dfs(int n, int num, vector<int> &ans)
    {
        if (num <= n)
            ans.push_back(num);
        else
            return;
        for (int d = 0; d < 10; d++)
        {
            num *= 10;
            num += d;
            if (num > n)
                break;
            dfs(n, num, ans);
            num -= d;
            num /= 10;
        }
        return;
    }
};
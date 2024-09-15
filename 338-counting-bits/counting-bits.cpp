class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                ans[0] = 0;
            if (i == 1)
                ans[1] = 1;
            ans[i] = (i & 1) + ans[i >> 1];
        }
        return ans;
    }
};
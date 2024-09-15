class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = countSetBits(i);
        }
        return ans;
    }

    int countSetBits(int n)
    {
        int ans = 0;
        while (n)
        {
            if (n & 1)
                ans++;
            n >>= 1;
        }
        return ans;
    }
};
class Solution
{
public:
    int numberOfSubstrings(string s, int k)
    {
        int n = s.size();
        int arr[130];
        if (k == 1)
        {
            return ((n * (n + 1)) / 2);
        }
        int l = 0;
        int r = 0;
        int ans = 0;

        while (r < n)
        {
            ++arr[s[r]];
            if (arr[s[r]] == k)
            {
                ans += n - r;
                while (l < r && arr[s[r]] == k)
                {
                    arr[s[l]]--;
                    ++l;
                    if (arr[s[r]] == k)
                        ans += n - r;
                }
            }
            ++r;
        }
        return ans;
    }
};
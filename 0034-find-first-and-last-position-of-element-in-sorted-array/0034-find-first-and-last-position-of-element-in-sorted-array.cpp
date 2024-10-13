int speedUp = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> searchRange(vector<int>& arr, int target)
    {
        int n = arr.size();

        int l = 0;
        int r = n - 1;
        int m;
        vector<int> ret;

        int ans = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (arr[m] == target)
            {
                ans = m;
                r = m - 1;
            }
            else if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        ret.push_back(ans);

        l = 0;
        r = n - 1;
        ans = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (arr[m] == target)
            {
                ans = m;
                l = m + 1;
            }
            else if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        ret.push_back(ans);

        return ret;
    }
};
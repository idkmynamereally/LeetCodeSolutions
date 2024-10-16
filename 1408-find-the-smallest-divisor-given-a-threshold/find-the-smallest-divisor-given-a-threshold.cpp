class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = 1;
        for (int i : nums)
            r = r > i ? r : i;

        int m;
        int ans = -1;
        while (l <= r)
        {
            m = l + floor((r - l) / 2);
            int val = getVal(nums, m);

            if (val <= threshold)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        return ans;
    }

    int getVal(vector<int> &nums, int div)
    {
        int ret = 0;
        for (int i : nums)
        {
            ret += ceil((double)i / div);
        }
        return ret;
    }
};
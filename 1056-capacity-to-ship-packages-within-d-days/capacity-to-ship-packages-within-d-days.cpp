class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int k)
    {
        int l = 1;
        int r = 0;
        

        for (int i : weights)
        {
            l = l > i ? l : i;
            r += i;
        }

        int m;
        int ans = -1;

        while (l <= r)
        {
            m = l + floor((r - l) / 2);
            int days = daysRequired(weights, m);

            if (days <= k)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }

    int daysRequired(vector<int> &arr, int cap)
    {
        int totalDays = 0;
        int curr = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (curr + arr[i] > cap)
            {
                totalDays++;
                curr = arr[i];
            }
            else
                curr += arr[i];
        }
        if (curr)
            totalDays++;
        return totalDays;
    }
};
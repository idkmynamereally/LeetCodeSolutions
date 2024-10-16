class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int r = arr[arr.size() - 1] + k;
        int i = 0;
        int ans = 1;
        for (ans = 1; i < arr.size() && ans <= r; ans++)
        {
            if (ans == arr[i])
            {
                i++;
                continue;
            }
            else
            {
                k--;
                if (k == 0)
                    return ans;
            }
        }

        ans += k - 1;
        return ans;
    }
};
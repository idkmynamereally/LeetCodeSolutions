class Solution {
public:
    int findMin(vector<int>& arr) {
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int m;
    int ans = INT_MAX;

    while (l <= r)
    {
        m = l + floor((r - l) / 2);

        if (arr[l] <= arr[r])
            return arr[l];

        if (arr[l] > arr[m]) // cut is in left side
        {
            r = m;
        }
        else
            l = m + 1;
        }
        return arr[0];   
    }
};
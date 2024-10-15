class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        int l = 1;
        int r = n - 2;
        int m;

        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        while (l <= r)
        {
            m = l + floor((r - l) / 2);

            if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1])
                return m;

            if (arr[m] < arr[m - 1])
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};
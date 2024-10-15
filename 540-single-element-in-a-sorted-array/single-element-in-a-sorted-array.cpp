class Solution {
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();

        int l = 0;
        int r = n - 1;
        int m;

        while (l <= r)
        {
            m = l + floor((r - l) / 2);
            if (m != 0 && arr[m] == arr[m - 1]) // always be at first occurrence
            {
                m--;
            }

            //cout << m << "\n";
            if (m == n - 1 || arr[m] != arr[m + 1])
                return arr[m];

            if (m % 2 == 0)
                l = m + 2;
            else
                r = m - 1;
        }
        return arr[m];
    }
};
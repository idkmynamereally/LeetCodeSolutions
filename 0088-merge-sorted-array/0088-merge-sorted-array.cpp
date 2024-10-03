class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0)
        {
            int a = nums1[m];
            int b = nums2[n];
            if (a > b)
            {
                nums1[i] = a;
                m--;
            }
            else
            {
                nums1[i] = b;
                n--;
            }
            i--;
        }
        while (n >= 0)
        {
            nums1[i--] = nums2[n--];
        }
    }
};
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();

        if (m % 2)
        {
            for (int i = 0; i < n; i++)
            {
                ans ^= nums1[i];
            }
        }

        if (n % 2)
        {
            for (int i = 0; i < m; i++)
            {
                ans ^= nums2[i];
            }
        }
        return ans;
    }
};
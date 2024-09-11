class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start ^ goal;
        int ans = 0;
        while (a)
        {
            ans += a % 2;
            a /= 2;
        }
        return ans;
    }
};
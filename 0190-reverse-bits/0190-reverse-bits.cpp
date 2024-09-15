class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int p = 31;
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
                ans += pow(2, p);
            p--;
            n >>= 1;
        }
        return ans;
    }
};
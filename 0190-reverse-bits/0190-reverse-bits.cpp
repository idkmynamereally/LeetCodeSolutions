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
            {
                uint32_t revbit = 1;
                revbit <<= p;
                ans += revbit;
            }
            n >>= 1;
            p--;
        }
        return ans;
    }
};
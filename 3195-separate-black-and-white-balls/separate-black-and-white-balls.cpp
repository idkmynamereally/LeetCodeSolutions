#define ll long long

class Solution {
public:
    long long minimumSteps(string s)
    {
        ll n = s.size();
        ll zeroCount = 0;
        ll swaps = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                zeroCount++;
                continue;
            }
            swaps += zeroCount;
        }
        return swaps;
    }
};
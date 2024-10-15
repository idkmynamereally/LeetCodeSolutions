#define ll long long

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

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
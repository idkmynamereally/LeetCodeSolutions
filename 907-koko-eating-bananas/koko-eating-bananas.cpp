#define ll long long

class Solution {
public:
    int gr;
    int minEatingSpeed(vector<int>& piles, int h) {
        gr = h;
        ll l = 1;
        ll r = *max_element(piles.begin(), piles.end());
        ll ans = 0;

        while (l <= r)
        {
            ll m = l + ((r - l) / 2);
            ll hr = timeToEat(piles, m);
            if (hr <= h)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }

    ll timeToEat(vector<int>& p, ll speed)
    {
        ll ret = 0;
        for (ll i : p)
        {
            ret += ceil((long double)i / speed);
        }
        return ret;
    }
};
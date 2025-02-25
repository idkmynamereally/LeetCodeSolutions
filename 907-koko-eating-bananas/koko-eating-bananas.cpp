#define ll long long

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll l = 1;
        ll r = *max_element(piles.begin(), piles.end());
        ll ans = 0;

        while (l <= r)
        {
            ll m = l + ((r - l) / 2);
            if (timeToEat(piles, m, h))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }

    bool timeToEat(vector<int>& p, ll speed, ll h)
    {
        for (int i : p)
        {
            h -= ceil((long double) i / speed);
            if (h < 0)
                return false;
        }
        return true;
    }
};
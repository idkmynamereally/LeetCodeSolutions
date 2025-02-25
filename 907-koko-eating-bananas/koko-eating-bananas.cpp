#define ll long long

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while (l <= r)
        {
            int m = l + ((r - l) / 2);
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

    bool timeToEat(vector<int>& p, int speed, int h)
    {
        for (int i : p)
        {
            h -= ceil((double) i / speed);
            if (h < 0)
                return false;
        }
        return true;
    }
};
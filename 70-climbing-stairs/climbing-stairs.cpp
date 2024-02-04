class Solution 
{
public:
    int climbStairs(int n) 
    {
        unordered_map<int, int> numberOfWays;
        numberOfWays[n] = 1;
        return memoize(numberOfWays, 0, n);
    }

    int memoize(unordered_map<int, int>& numberOfWays, int n, int target)
    {
        if (n > target)
            return 0;
        if (!numberOfWays.contains(n))
            numberOfWays[n] = memoize(numberOfWays, n + 1, target) + memoize(numberOfWays, n + 2, target);
        return numberOfWays[n];
    }
};
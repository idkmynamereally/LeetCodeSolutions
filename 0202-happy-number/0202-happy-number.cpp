class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        set.insert(n);
        return recurse(n, set);
    }

    bool recurse(int n, unordered_set<int> &set)
    {
        if (n == 1)
            return true;
        int ans = 0;
        while (n)
        {
            int digit = n % 10;
            ans += digit * digit;
            n /= 10;
        }
        if (set.count(ans))
            return false;
        set.insert(ans);
        return recurse(ans, set);
    }
};
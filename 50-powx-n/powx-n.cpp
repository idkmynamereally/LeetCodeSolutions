#define ll long long

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 0;
        ll p = n;
        if (n < -1)
            ans = binpow(x, -p);
        else
            ans = binpow(x, p);
        if (n < 0)
            return 1 / ans;
        return ans;
    }

    double binpow(double x, ll n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        double ret = binpow(x, n / 2);
        ret *= ret;
        if (n & 1)
            return ret * x;
        else
            return ret;
    }
};

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        recurse(ans, a, b, c, 0, 0, 0);
        return ans;
    }

    void recurse(string &s, int a, int b, int c, int aC, int bC, int cC)
    {
        if ((a && (a >= b && a >= c) && aC != 2) || (a > 0 && (bC == 2 || cC == 2)))
        {
            s.push_back('a');
            aC++;
            bC = cC = 0;
            a--;
            recurse(s, a, b, c, aC, bC, cC);
            return;
        }
        if ((b && (b >= a && b >= c) && bC != 2) || (b > 0 && (aC == 2 || cC == 2)))
        {
            s.push_back('b');
            bC++;
            aC = cC = 0;
            b--;
            recurse(s, a, b, c, aC, bC, cC);
            return;
        }
        if ((c && (c >= a && c >= b) && cC != 2) || (c > 0 && (aC == 2 || bC == 2)))
        {
            s.push_back('c');
            cC++;
            bC = aC = 0;
            c--;
            recurse(s, a, b, c, aC, bC, cC);
            return;
        }
    }
};
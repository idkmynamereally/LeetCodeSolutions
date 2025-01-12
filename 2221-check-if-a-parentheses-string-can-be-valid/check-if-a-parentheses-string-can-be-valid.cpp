class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2)
            return false;

        int o = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(' || locked[i] == '0')
                o++;
            else if (o > 0)
                o--;
            else
                return false;
        }

        int x = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (c == ')' || locked[i] == '0')
                x++;
            else if (x > 0)
                x--;
            else
                return false;
        }

        return true;
    }
};
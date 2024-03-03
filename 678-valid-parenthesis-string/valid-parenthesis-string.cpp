class Solution
{
public:
    bool checkValidString(string s)
    {
        int starCount = 0;
        int openCount = 0;
        for (char c : s)
        {
            //std::cout << c << openCount << " " << starCount << "\n";
            if (c == '(')
                openCount++;
            else if (c == '*')
                starCount++;
            else
            {
                if (openCount > 0)
                {
                    openCount--;
                }
                else
                {
                    if (starCount > 0)
                    {
                        starCount--;
                    }
                    else
                        return false;
                }
            }
        }
        if (openCount <= 0)
            return true;

        int closeCount = 0;
        starCount = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (c == ')')
                closeCount++;
            else if (c == '*')
                starCount++;
            else
            {
                if (closeCount == 0)
                {
                    if (starCount)
                    {
                        starCount--;
                    }
                    else
                        return false;
                }
                else
                    closeCount--;
            }
        }
        return true;
    }
};
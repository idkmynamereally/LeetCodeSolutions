class Solution {
public:
    bool isPalindrome(std::string s) 
    {
        std::string s2;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c >= 97 && c <= 122)    //lowercase letters
            {
                s2.push_back(c);
                continue;
            }
            if (c >= 48 && c <= 57)     //numerics
            {
                s2.push_back(c);
                continue;
            }
            if (c >= 65 && c <= 90)     //uppercase to lowercase
            {
                s2.push_back(c + 32);
                continue;
            }
            else                        //remove non alphanumerics
            {
                continue;
            }
        }
        for (int l = 0, r = s2.length() - 1; l < r; l++, r--)
        {
            if (s2[l] != s2[r])
                return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isPalindrome(std::string s) 
    {
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c >= 97 && c <= 122)    //lowercase letters
                continue;
            if (c >= 48 && c <= 57)     //numerics
                continue;
            if (c >= 65 && c <= 90)     //uppercase to lowercase
                s[i] = c + 32;
            else                        //remove non alphanumerics
            {
                s.erase(i, 1);
                i--;
            }
        }
        for (int l = 0, r = s.length() - 1; l < r; l++, r--)
        {
            if (s[l] != s[r])
                return false;
        }
        return true;
    }
};
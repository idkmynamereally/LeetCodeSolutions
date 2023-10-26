class Solution {
public:
    bool isPalindrome(std::string s) 
    {
        int l = 0;
        int r = s.length() - 1;
        while(l < r)
        {
            char cl = s[l];
            char cr = s[r];
            if (!isalnum(cl))
            {
                l++;
                continue;
            }
            if (!isalnum(cr))
            {
                r--;
                continue;
            }
            if (cl < 91)
                cl += 32;
            if (cr < 91)
                cr += 32;
            if (cl != cr)
                return false;
            l++;
            r--;
        }
        return true;
    }
};
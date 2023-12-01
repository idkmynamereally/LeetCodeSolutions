class Solution {
public:
    int characterReplacement(std::string s, int k) 
    {
        int l{ 0 };
        int r{ 0 };
        int maxSize{ 0 };
        int maxf{ 1 };
        std::unordered_map<char, int> m{};
        m[s[r]]++;
        
        while (r < s.size())
        {
            if (isStringValid(r-l+1, maxf, k))
            {
                maxSize = maxSize > (r - l + 1) ? maxSize : (r - l + 1);
                r++;
                m[s[r]]++;
                maxf = maxf > m[s[r]] ? maxf : m[s[r]];
            }
            else
            {
                m[s[l]]--;
                l++;
            }
        }
        return maxSize;
    }

    int getMaxCharCount(std::unordered_map<char, int>& m)
    {
        int max{ 0 };
        for (const auto& i : m)
        {
            if (i.second > max)
                max = i.second;
        }
        return max;
    }

    bool isStringValid(int subStrSize, int highestCharCount, int k)
    {
        if (subStrSize - highestCharCount <= k)
            return true;
        else
            return false;
    }
};
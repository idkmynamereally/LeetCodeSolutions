class Solution {
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        std::unordered_set<char> m;
        int maxSize{ 0 };
        int currSize{ 0 };
        int l{ 0 };
        int r{ 0 };

        for (r = 0; r < s.size(); r++)
        {
            while (m.contains(s[r]))
            {
                m.erase(s[l]);
                l++;
            }
            currSize = r - l + 1;
            m.insert(s[r]);
            maxSize = maxSize > currSize ? maxSize : currSize;
        }
        return maxSize;
    }
};
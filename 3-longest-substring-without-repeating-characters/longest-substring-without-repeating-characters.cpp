class Solution {
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        std::unordered_map<char, int> m;
        int maxSize{ 0 };
        int currSize{ 0 };
        for (int i{ 0 }; i < s.size(); i++)
        {
            char currChar = s[i];
            if (m.contains(currChar))
            {
                i = m[currChar];
                currSize = 0;
                m.clear();
            }
            else
            {
                currSize++;
                m[currChar] = i;
                maxSize = maxSize > currSize ? maxSize : currSize;
            }
        }
        return maxSize;
    }
};
class Solution
{
public:

    bool check_permutation(const std::unordered_map<char, int>& a, const std::unordered_map<char, int>& b)
    {
        if (a == b)
            return true;
        return false;
    }

    bool checkInclusion(std::string s1, std::string s2)
    {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s1Size > s2Size)
            return false;
        std::unordered_map<char, int> s1Map;
        std::unordered_map<char, int> s2Map;

        char c = 'a';
        for (int i = 0; i < 26; i++)
        {
            s1Map[c] = 0;
            s2Map[c] = 0;
            c++;
        }
        for (char c : s1)
        {
            s1Map[c]++;
        }

        for (int i = 0; i < s1Size; i++)
        {
            s2Map[s2[i]]++;
        }

        for (int i = 0; i <= (s2Size - s1Size); i++)
        {
            if (check_permutation(s1Map, s2Map))
            {
                return true;
            }
            s2Map[s2[i]]--;
            if ((i + s1Size) < s2Size)
                s2Map[s2[i+s1Size]]++;
        }
        return false;
    }
};
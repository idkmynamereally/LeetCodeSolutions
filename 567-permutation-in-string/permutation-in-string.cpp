class Solution
{
public:

    bool check_permutation(int* a, int* b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(std::string s1, std::string s2)
    {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s1Size > s2Size)
            return false;
        int s1Map[26]{};
        int s2Map[26]{};

        for (char c : s1)
        {
            s1Map[c - 'a']++;
        }

        for (int i = 0; i < s1Size; i++)
        {
            s2Map[s2[i] - 'a']++;
        }

        for (int i = 0; i <= (s2Size - s1Size); i++)
        {
            if (check_permutation(s1Map, s2Map))
            {
                return true;
            }
            s2Map[s2[i] - 'a']--;
            if ((i + s1Size) < s2Size)
                s2Map[s2[i+s1Size] - 'a']++;
        }
        return false;
    }
};
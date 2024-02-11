class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_map<string, unordered_map<int, bool>> map;
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (recurse(s, i, wordDict, map))
                return true;
        }
        return false;
    }

    bool recurse(string_view s, int wordIndex, vector<string>& wordDict, unordered_map<string, unordered_map<int, bool>>& map)
    {
        string s1 = string(s);
        if (map.contains(s1))
        {
            if (map[s1].contains(wordIndex))
                return map[s1][wordIndex];
        }
        if (s == "")
        {
            map[s1][wordIndex] = true;
            return true;
        }

        if (wordDict[wordIndex].size() > s.size())
        {
            map[s1][wordIndex] = false;
            return false;
        }

        if (wordDict[wordIndex] == s.substr(0, wordDict[wordIndex].size()))
        {
            auto leftString = s.substr(wordDict[wordIndex].size(), s.size() - wordDict[wordIndex].size());
            for (int i = 0; i < wordDict.size(); i++)
            {
                //std::cout << wordDict[i] << " " << leftString << "\n";
                if (recurse(leftString, i, wordDict, map))
                    return true;
            }
        }
        map[s1][wordIndex] = false;
        return false;
    }
};
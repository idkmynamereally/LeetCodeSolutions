class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> arr(s.size() + 1, false);
        arr[s.size()] = true;
        for (int sIndex = s.size(); sIndex >= 0; sIndex--)
        {
            for (int wIndex = 0; wIndex < wordDict.size(); wIndex++)
            {
                if (arr[sIndex])
                    break;
                recurse(s, sIndex, wIndex, wordDict, arr);
            }
        }
        return arr[0];
    }

    void recurse(string_view s, int currIndex, int wordIndex, vector<string>& wordDict, vector<bool>& arr)
    {
        std::cout << wordDict[wordIndex] << " " << s.substr(currIndex, s.size() - currIndex) << "\n";
        if (wordDict[wordIndex].size() > (s.size() - currIndex))
        {
            arr[currIndex] = false;
            return;
        }

        string_view s1 = s.substr(currIndex, wordDict[wordIndex].size());
        if (s1 == wordDict[wordIndex])
        {
            arr[currIndex] = arr[currIndex + wordDict[wordIndex].size()];
        }
    }
};
class Solution {
public:
    /*bool checkWindow(std::unordered_map<char, int>& window, std::unordered_map<char, int>& substring)
    {
        for (const auto& charAndCount : substring)
        {
            char c = charAndCount.first;
            if (window[c] >= substring[c])
            {
                continue;
            }
            return false;
        }
        return true;
    }*/

    string minWindow(string s, string t)
    {
        if (t.size() == 1)
        {
            if (s.find(t) == std::string::npos)
                return "";
            return t;
        }
        std::unordered_map<char, int> window;
        std::unordered_map<char, int> substring;
        std::string ans;
        int ansSize = INT_MAX;

        for (char c : t)
        {
            substring[c]++;
        }

        int l = 0;
        int r = 0;
        int have = 0; 
        int need = t.size();

        for (;r < s.size(); r++)
        {
            if (substring.contains(s[r]))
            {
                window[s[r]]++;
                if (window[s[r]] <= substring[s[r]])
                    have++;
                if (have == need)
                {
                    if (ansSize > (r - l + 1))
                    {
                        ans = s.substr(l, (r - l + 1));
                        ansSize = r - l + 1;
                    }
                    while (l < r && have == need)
                    {
                        if (substring.contains(s[l]))
                        {
                            window[s[l]]--;
                            if (window[s[l]] < substring[s[l]])
                            {
                                if (ansSize > (r - l + 1))
                                {
                                    ans = s.substr(l, (r - l + 1));
                                    ansSize = r - l + 1;
                                }
                                have--;
                            }
                        }
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int l = 0;
        int r = 0;
        while (l < s1.size())
        {
            while (r < s1.size() && s1[r] != ' ')
                r++;
            mp[s1.substr(l, r - l)]++;
            r++;
            l = r;
        }
        l = 0;
        r = 0;
        while (l < s2.size())
        {
            while (r < s2.size() && s2[r] != ' ')
                r++;
            mp[s2.substr(l, r - l)]++;
            r++;
            l = r;
        }

        vector<string> ans;
        for (const auto& p : mp)
        {
            if (p.second == 1)
                ans.push_back(p.first);
        }
        return ans;
    }
};
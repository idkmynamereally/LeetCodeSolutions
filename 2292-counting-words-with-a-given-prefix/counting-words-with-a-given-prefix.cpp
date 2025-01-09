class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int ans = 0;
        for (string_view s : words)
        {
            if (match(s, pref))
                ans++;
        }
        return ans;
    }

    bool match(string_view s, string_view p)
    {
        int j = 0;
        for (int i = 0; i < p.size(); i++, j++)
        {
            if (s[j] != p[i])
                return false;
        }
        return true;
    }
};
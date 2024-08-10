class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            commonPrefix(ans, strs[i]);
        }
        return ans;
    }

    void commonPrefix(string& s, string_view s2)
    {
        if (s == "")
            return;
        int i = 0;
        while (i < s.size() && i < s2.size() && s[i] == s2[i]){
            i++;
        }
        if (s.size() <= i)
            return;
        s.erase(s.begin() + i, s.end());
    }
};
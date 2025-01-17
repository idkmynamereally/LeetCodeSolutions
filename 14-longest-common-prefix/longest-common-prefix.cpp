class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = "";
        if (strs.size() == 1)
            return strs[0];
        ans = common(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++)
        {
            ans = common(ans, strs[i]);
        }

        return ans;
    }

    string common(string& s, string& t)
    {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] != t[i])
                break;
            i++; j++;
        }
        return s.substr(0, i);
    }
};
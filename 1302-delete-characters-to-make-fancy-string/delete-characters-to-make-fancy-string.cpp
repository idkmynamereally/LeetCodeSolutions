class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && i != n - 1 && s[i - 1] == s[i + 1] && s[i - 1] == s[i])
                continue;
            ans.push_back(s[i]);
        }

        return ans;
    }
};
class Solution {
public:
    int isPrefixOfWord(string s, string p) {
        int n = s.size();
        int m = p.size();
        int ans = 1;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (j < m && s[i] == p[j])
            {
                j++;
                if (j == m)
                    return ans;
            }
            else
            {
                while (i < n && s[i] != ' ')
                    i++;
                j = 0;
                ans++;
            }
        }
        return -1;
    }
};
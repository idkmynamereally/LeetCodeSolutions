class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        int n = s.size();
        vector<int> mp(26, 0);
        int ans = 0;

        for (char c : s)
            mp[c - 'a']++;

        for (char c = 0; c <= 25; c++)
        {
            if (!mp[c])
                continue;
            ans++;
            if (mp[c] % 2 == 0)
                ans++;
        }

        return ans;
    }
};
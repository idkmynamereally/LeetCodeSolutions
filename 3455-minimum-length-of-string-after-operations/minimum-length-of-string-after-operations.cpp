class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0;

        for (char c : s)
            mp[c]++;

        for (char c = 'a'; c <= 'z'; c++)
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
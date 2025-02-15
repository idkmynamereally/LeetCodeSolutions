class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (string s : strs)
        {
            string key = "";
            unordered_map<char, int> cnt;
            for (char c : s)
                cnt[c]++;
            for (char c = 'a'; c <= 'z'; c++)
            {
                key.push_back(c);
                key += (to_string(cnt[c]));
            }
            mp[key].push_back(s);
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
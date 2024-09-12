class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;
        for (char c : allowed)
            set.insert(c);

        int ans = 0;

        for (const auto& s : words)
        {
            int i = 0;
            for (i = 0; i < s.size(); i++)
            {
                if (!set.contains(s[i]))
                    break;
            }
            if (i == s.size())
                ans++;
        }
        return ans;
    }
};
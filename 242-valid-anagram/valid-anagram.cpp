class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sc (26);
        vector<int> tc (26);

        for (char c : s)
            sc[c - 'a']++;

        for (char c : t)
            tc[c - 'a']++;

        for (char c = 'a'; c <= 'z'; c++)
            if (sc[c - 'a'] != tc[c - 'a'])
                return false;
        return true;
    }
};
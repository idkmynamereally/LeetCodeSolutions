class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<char, char> mp;
        unordered_set<char> mp2;
        int i = 0;
        int j = 0;
        for (; i < s.size(); i++)
        {
            if (mp.count(s[i]) || mp2.contains(t[i]))
            {
                if (t[i] != mp[s[i]])
                {
                    return false;
                }
            }
            else
            {
                mp[s[i]] = t[i];
                mp2.insert(t[i]);
            }
        }
        return true;
    }
};
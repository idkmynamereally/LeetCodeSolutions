class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;
        vector<int> ret(a.size(), 0);
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (s.contains(a[i]))
                ans++;
            s.insert(a[i]);
            if (s.contains(b[i]))
                ans++;
            s.insert(b[i]);
            ret[i] = ans;
        }
        return ret;
    }
};
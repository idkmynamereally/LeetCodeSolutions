class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            string st = strs[i];
            sort(st.begin(), st.end());
            m[st].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto p : m)
        {
            ans.push_back(p.second);
        }

        return ans;
    }
};
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ans;
        vector<int> m(26, -1);

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            m[c - 'a'] = i;
        }

        int end = m[s[0] - 'a'];
        int prev = -1;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            end = end > m[c - 'a'] ? end : m[c - 'a'];
            if (i == end)
            {
                ans.push_back(end - prev);
                prev = end;
            }
        }
        return ans;
    }
};
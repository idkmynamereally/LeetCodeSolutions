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
            end = end > m[s[i] - 'a'] ? end : m[s[i] - 'a'];
            if (i == end)
            {
                ans.push_back(end - prev);
                prev = end;
            }
        }
        return ans;
    }
};
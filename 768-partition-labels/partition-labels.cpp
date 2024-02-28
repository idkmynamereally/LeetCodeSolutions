class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        std::pair<int, int> p(-1, -1);
        vector<pair<int, int>> map(26, p);
        vector<int> ans;
        
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (map[c - 'a'].first == -1)
                map[c - 'a'].first = i;
            map[c - 'a'].second = i;
        }
        std::sort(map.begin(), map.end(), [](pair<int, int> a, pair<int, int> b)
            {
                return(a.first < b.first);
            });
        /*for (int i = 0; i < map.size(); i++)
        {
            cout << map[i].first << " " << map[i].second << "\n";
        }*/
        
        int part = 0;
        int lastPart = 0;
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i].first == -1)
                continue;
            if (map[i].first > part)
            {
                //cout << part << " -> " << map[i].first << " " << map[i].second << "\n";
                part++;
                ans.push_back(part - lastPart);
                lastPart = part;
                part = part > map[i].second ? part : map[i].second;
            }
            else if(map[i].first <= part)
            {
                part = part > map[i].second ? part : map[i].second;
            }
        }
        ans.push_back(part - lastPart + 1);
        return ans;
    }
};
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<vector<int>, vector<string>> groups{};     //All groups <anagramMap, Strings    
        string str{};
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> anagramMap(26);
            str = strs[i];
            for (const char& c : str)
            {
                anagramMap[c - 97]++;
            }
            groups[anagramMap].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto& v : groups)
        {
            ret.push_back(v.second);
        }
        return ret;
    }
};
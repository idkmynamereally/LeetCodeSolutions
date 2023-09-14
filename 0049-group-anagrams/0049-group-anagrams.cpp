class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<map<char, int>, vector<string>> groups{};     //All groups <anagramMap, Strings    
        string str{};
        for (int i = 0; i < strs.size(); i++)
        {
            map<char, int> anagramMap{};
            str = strs[i];
            for (char c : str)
            {
                if (anagramMap.contains(c))
                    anagramMap[c]++;
                else
                    anagramMap[c] = 1;
            }
            groups[anagramMap].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (pair<map<char, int>, vector<string>> v : groups)
        {
            ret.push_back(v.second);
        }
        return ret;
    }
};
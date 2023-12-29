class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        //<nums, frequency>
        std::unordered_map<int, int> m{};
        for (int i : nums)
        {
            m[i]++;
        }
        std::vector<std::pair<int, int>> mapList;
        for (const auto& i : m)
        {
            mapList.push_back(i);
        }
        std::sort(mapList.begin(), mapList.end(), [](std::pair<int, int> a, std::pair<int, int> b) 
        {
                return a.second > b.second;
        });
        std::vector<int> ret;

        for (int i = 0; i < k; i++)
        {
            ret.push_back(mapList[i].first);
        }
        return ret;
    }
};
class Solution
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k)
	{
		std::vector<std::pair<int, int>> v;
		std::unordered_map<int, int> m;
		for (int i : nums)
		{
			if (m.contains(i))
			{
				m[i]++;
			}
			else
			{
				m[i] = 1;
			}
		}
		for (auto it : m) 
		{
			v.push_back(it);
		}
		std::sort
		(v.begin(), v.end(), 
			[](std::pair<int, int> a, std::pair<int, int> b)
			{
				return a.second > b.second;
			}
		);
		std::vector<int> ret;
		auto it = v.begin();
		for (int i = 0; i < k; i++)
		{
			ret.push_back((*it).first);
			it++;
		}
		return ret;
	}
};
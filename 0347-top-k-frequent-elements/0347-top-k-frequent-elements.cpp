class Solution
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k)
	{
		std::unordered_map<int, int> m;
		for (const int& i : nums)
		{
			m[i]++;
		}
		
		std::vector<std::pair<int, int>> sorter;

		for (const auto& p : m)
		{
			sorter.push_back(p);
		}

		std::sort(sorter.begin(), sorter.end(),
			[](const std::pair<int, int>& a, const std::pair<int, int>& b)
			{
				return a.second > b.second;
			}
		);
		
		std::vector<int> ret;
		int i = 0;
		for (const auto& p : sorter)
		{
			ret.push_back(p.first);
			++i;
			if (i == k)
			{
				break;
			}
		}
		return ret;
	}
};
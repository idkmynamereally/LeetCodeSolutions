class Solution 
{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::vector<int> ans(k);
        std::map<int, int> freq;

        for (const auto& i : nums)  //Got frequency of all numbers...
        {
            freq[i]++;
        }

        std::vector<std::pair<int, int>> sorter(std::size(freq));

        for (const auto& p : freq)
        {
            sorter.push_back(p);
        }

        std::sort(sorter.begin(), sorter.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            {
                return a.second > b.second;
            });
        //Sort vector on basis of frequency.
        int count = 0;
        for (const auto& i : sorter)    //From the vector sorted in descending on frequency we get the first k elements
        {
            ans[count] = (i.first);
            count++;
            if (count == k)
                break;
        }
        return ans;
    }
};
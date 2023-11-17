class Solution 
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        ios_base::sync_with_stdio(0),cin.tie(0);
        std::vector<int> ans(std::size(temperatures));
        std::stack<std::pair<int, int>> tempStack{};      //<temperature, index>
        int currTemp{};
        for (int i = 0; i < std::size(temperatures); i++)
        {
            currTemp = temperatures[i];
            while (!(tempStack.empty()) && currTemp > tempStack.top().first)
            {
                int topIndex = tempStack.top().second;
                ans[topIndex] = i - topIndex;
                tempStack.pop();
            }
            tempStack.push(std::pair(currTemp, i));
        }
        return ans;
    }
};
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0)
            return 0;
        int ans = INT_MAX;
        unordered_map<int, unordered_map<int, int>> map;    //<amount, <index, coins>>

        for (int i = 0; i < coins.size(); i++)
        {
            int temp = recurse(coins, amount, i, map);
            if (temp == -1)
                continue;
            if (temp < ans)
                ans = temp;
        }
        int count = 0;
        if (ans == INT_MAX)
            return -1;
        return ans;
    }

    int recurse(vector<int>& coins, int amount, int currIndex, unordered_map<int, unordered_map<int, int>>& map)
    {
        //std::cout << "CurrElemenet : " << coins[currIndex] << " Amount : " << amount << "\n";
        if (map.contains(amount))
        {
            if (map[amount].contains(currIndex))
                return (map[amount])[currIndex];
        }
        if (amount == coins[currIndex])
            return 1;
        if (amount < coins[currIndex])
            return -1;

        amount -= coins[currIndex];

        int min = INT_MAX;
        for (int i = currIndex; i < coins.size(); i++)
        {
            int temp = recurse(coins, amount, i, map);
            if (temp == -1)
                continue;
            min = temp < min ? temp : min;
        }
        if (min == INT_MAX)
        {
            (map[amount])[currIndex] = -1;
            return -1;
        }
        (map[amount])[currIndex] = min;
        return min + 1;
    }
};
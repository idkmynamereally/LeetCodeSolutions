class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        unordered_map<int, unordered_map<int, int>> map;
        return recurse(coins, amount, 0, map);
    }

    int recurse(vector<int>& coins, int amount, int currIndex, unordered_map<int, unordered_map<int, int>>& map)
    {
        if (map.contains(amount))
        {
            if (map[amount].contains(currIndex))
                return map[amount][currIndex];
        }
        if (currIndex >= coins.size())
            return -1;
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int temp1 = recurse(coins, amount - coins[currIndex], currIndex, map);
        int temp2 = recurse(coins, amount, currIndex + 1, map);
        int ans{-1};
        
        if (temp1 == -1 && temp2 == -1)
        {
            map[amount][currIndex] = -1;
        }
        else if (temp1 == -1)
        {
            map[amount][currIndex] = temp2;
        }
        else if (temp2 == -1)
        {
            temp1++;
            map[amount][currIndex] = temp1;
        }
        else
        {
            temp1++;
            map[amount][currIndex] = (temp1 < temp2 ? temp1 : temp2);
        }
        return map[amount][currIndex];
    }
};
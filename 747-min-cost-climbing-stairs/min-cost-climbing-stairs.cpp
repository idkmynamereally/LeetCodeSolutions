class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        unordered_map<int, int> map;
        map[cost.size() - 1] = cost[cost.size() - 1];
        map[cost.size() - 2] = cost[cost.size() - 2];
        return min(recurse(map, cost, 0), recurse(map, cost, 1));
    }

    int recurse(unordered_map<int, int>& map, vector<int>& cost, int i)
    {
        if (i >= cost.size())
            return 0;
        if (map.contains(i))
            return map[i];

        map[i] = cost[i] + min(recurse(map, cost, i + 1), recurse(map, cost, i + 2));
        return map[i];
    }

    //cost of going from stair i to end = min(map[i + 1], map[i + 2])
};